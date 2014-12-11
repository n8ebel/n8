/*
 *  ResourceManagerService.cpp
 *  goobar
 *
 *  Created by Nate Ebel on 3/21/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#include <fstream>

#include "ResourceManager.h"
#include "Log.h"

#define TAG "ResourceManager"

/** Constructor
 *  
 *  @param p_window Pointer to game window.  Used to load image resources.
 *  @param p_path Path to resources directory
 */
n8::ResourceManager::ResourceManager(std::shared_ptr<n8::Game> game, std::shared_ptr<n8::Window> p_window, std::string p_path) : Service(game){
    
    m_gameWindow = p_window;
    m_resourcesListPath = p_path;
    
    LoadResources();
}

/** Destructor
 *  Deletes all loaded resources
 */

n8::ResourceManager::~ResourceManager() {
    Log::Info(TAG, "Destructor");
    m_loadedTextures.clear();
    m_loadedMusic.clear();
    m_loadedSoundEffects.clear();
    m_loadedFonts.clear();
}

void n8::ResourceManager::LoadResources(){
    
    tinyxml2::XMLDocument resourcesListFile;
    tinyxml2::XMLElement* root = nullptr;
    tinyxml2::XMLElement* idElement = nullptr;
    
    resourcesListFile.LoadFile( m_resourcesListPath.c_str());
    
    root = resourcesListFile.FirstChildElement( RESOURCES_TAG.c_str() );
    
    if(root){        
        // Get Textures
        tinyxml2::XMLElement* textureElements = root->FirstChildElement( TEXTURE_RESOURCES_TAG.c_str() );
        
        tinyxml2::XMLElement* textureElement = textureElements->FirstChildElement(TEXTURE_TAG.c_str());
        for( textureElement; textureElement; textureElement = textureElement->NextSiblingElement()){
            
            idElement = textureElement->FirstChildElement(ID_TAG.c_str());
            std::string texturePath = textureElement->GetText();
            std::string textureID = idElement->GetText();
            
            Log::Debug( TAG,"Loading Texture: " + texturePath + " with ID: " + textureID );
            LoadTexture(texturePath,textureID);
        }
        
        // Get SoundEffects
        tinyxml2::XMLElement* soundEffectElements = root->FirstChildElement( SOUND_EFFECT_RESOURCES_TAG.c_str() );
        
        tinyxml2::XMLElement* soundEffectElement = soundEffectElements->FirstChildElement(SOUND_EFFECT_TAG.c_str());
        for( soundEffectElement; soundEffectElement; soundEffectElement = soundEffectElement->NextSiblingElement()){
            
            idElement = soundEffectElement->FirstChildElement(ID_TAG.c_str());
            std::string soundEffectPath = soundEffectElement->GetText();
            std::string effectID = idElement->GetText();
            
            Log::Debug(TAG, "Loading SoundEffect: " + soundEffectPath +" with ID: " + effectID );
            LoadSoundEffect(soundEffectPath,effectID);
        }
        
        // Get Music
        tinyxml2::XMLElement* musicElements = root->FirstChildElement( MUSIC_RESOURCES_TAG.c_str() );
        
        tinyxml2::XMLElement* musicElement = musicElements->FirstChildElement(MUSIC_TAG.c_str());
        for( musicElement; musicElement; musicElement = musicElement->NextSiblingElement()){
            
            idElement = musicElement->FirstChildElement(ID_TAG.c_str());
            std::string musicPath = musicElement->GetText();
            std::string musicID = idElement->GetText();
            
            Log::Debug(TAG, "Loading Music: " + musicPath + " with ID: " + musicID );
            LoadMusic(musicPath,musicID);
        }
        
        // Get Font
        tinyxml2::XMLElement* fontElements = root->FirstChildElement( FONT_RESOURCES_TAG.c_str() );
        
        tinyxml2::XMLElement* fontElement = fontElements->FirstChildElement(FONT_TAG.c_str());
        for( fontElement; fontElement; fontElement = fontElement->NextSiblingElement()){
            
            tinyxml2::XMLElement* sizeElement = fontElement->FirstChildElement(SIZE_TAG.c_str());
            idElement = fontElement->FirstChildElement(ID_TAG.c_str());
            
            std::string fontPath = fontElement->GetText();
            int fontSize = atoi( sizeElement->GetText() );
            std::string fontID = idElement->GetText();
            
            std::stringstream ss;//create a stringstream
            ss << ("Loading Font: " + fontPath + "with Size: ");
            ss << fontSize;
            ss << (" with ID: " + fontID);
            
            std::string msg = ss.str();
            
            Log::Debug(TAG, msg);
            
            
            LoadFont(fontPath, fontID, fontSize);
        }
    }
    else{
        Log::Error(TAG, "Couldn't load root element of resources file list");
    }
}

/** 
 *  Loads Texture resources.
 */
void n8::ResourceManager::LoadTexture(std::string p_filename, std::string p_id){
    SDL_Texture* texture = nullptr;
    int texW = 0;
    int texH = 0;
    
    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( p_filename.c_str() );
    if( loadedSurface == nullptr )
    {
        std::string msg("  Unable to load texture " + p_filename + " SDL_image Error: " + IMG_GetError() );
        Log::Error(TAG, msg);
    }
    else
    {
        //Create texture from surface pixels
        auto renderer = const_cast<SDL_Renderer*>(&m_gameWindow->GetRenderer());
        
        texture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
        if( texture == nullptr )
        {
            std::string msg( "  Unable to create texture from " + p_filename + " SDL Error: " +SDL_GetError() );
            Log::Error(TAG, msg);
        }
        
        texW = loadedSurface->w;
        texH = loadedSurface->h;
        
        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }
    
    if (texture != nullptr) {
        auto sharedPointer = std::make_shared<Texture>(p_filename, texture, texW, texH);
        m_loadedTextures[p_id] = sharedPointer;
        Log::Debug(TAG, "  Successfully loaded texture: " + p_filename);
    }
}

/** Loads music resources
 *  
 *  @param p_filename Name of the resource file to load into a Music object
 */
void n8::ResourceManager::LoadMusic(std::string p_filename, std::string p_id){
    Mix_Music* music = Mix_LoadMUS(p_filename.c_str());
    
    if(music != nullptr){
        m_loadedMusic[p_id] = std::make_shared<Music>(p_filename, music);
        Log::Debug(TAG, "  Successfully loaded music: " + p_filename);
    }
    else{
        Log::Error(TAG, "  Failed to load music: " + p_filename);
    }
}

/** Loads sound effect resources
 *
 *  @param p_filename Name of the resource file to load into a SoundEffect object
 *  @param p_id The identifier for the SoundEffect object.  Acts as the key for the object in the resource map

 */
void n8::ResourceManager::LoadSoundEffect(std::string p_filename, std::string p_id){
    Mix_Chunk* soundEffect = Mix_LoadWAV(p_filename.c_str());
    
    if(soundEffect != nullptr){
        m_loadedSoundEffects[p_id] = std::make_shared<SoundEffect>(p_filename, soundEffect);
        Log::Debug(TAG, "  Successfully loaded sound effect: " + p_filename);
    }
    else{
        Log::Error(TAG, "  Failed to load sound effect: " + p_filename);
    }
}

/** LoadFont
 *  Loads font resources specified by Resources.xml
 *
 *  @param p_filename Filename of font to load
 *  @param p_id The identifier for the font object.  Acts as the key for the object in the resource map
 *  @param p_size The font size of the desired font object
 */
void n8::ResourceManager::LoadFont(std::string p_filename, std::string p_id, int p_size){
    TTF_Font* font = TTF_OpenFont( p_filename.c_str(), p_size );
    
    if(font != nullptr){
        m_loadedFonts[p_id] = std::make_shared<Font>(p_filename, font);
        Log::Debug(TAG, "  Successfully loaded font: " + p_filename);
    }
    else{
        
        Log::Error(TAG, "  Failed to load font: " + p_filename + "  " + TTF_GetError());
    }
    TTF_CloseFont(font);
}

/** GetTexture
 *  Used to get a texture resource from the resource manager
 *
 *  @param p_resourceID The identifer for the desired resource.
 *
 *  @return A const reference to the specified texture, nullptr otherwise
 */
const std::shared_ptr<n8::Texture>& n8::ResourceManager::GetTexture(std::string p_resourceID) const{
    return m_loadedTextures.at(p_resourceID);
}

/** GetMusic
 *  Used to get a music resource from the resource manager
 *
 *  @param p_resourceID The identifer for the desired resource.
 *
 *  @return A const reference to the specified music object, nullptr otherwise
 */
const std::shared_ptr<n8::Music>& n8::ResourceManager::GetMusic(std::string p_resourceID) const{
    return m_loadedMusic.at(p_resourceID);
}

/** GetSoundEffect
 *  Used to get a SoundEffect resource from the resource manager
 *
 *  @param p_resourceID The identifer for the desired resource.
 *
 *  @return A const reference to the specified SoundEffect resource, nullptr otherwise
 */
const std::shared_ptr<n8::SoundEffect>& n8::ResourceManager::GetSoundEffect(std::string p_resourceID) const{
    return m_loadedSoundEffects.at(p_resourceID);
}

/** GetFont
 *  Used to get a Font resource from the resource manager
 *
 *  @param p_resourceID The identifer for the desired resource.
 *
 *  @return A const reference to the specified Font resource, nullptr otherwise
 */
const std::shared_ptr<n8::Font>& n8::ResourceManager::GetFont(std::string p_resourceID) const{
    return m_loadedFonts.at(p_resourceID);
}

void n8::ResourceManager::OnNotify(std::shared_ptr<Event> event){ }

