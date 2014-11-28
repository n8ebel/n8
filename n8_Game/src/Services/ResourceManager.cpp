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
n8::ResourceManager::ResourceManager(Game* game, Window* p_window, std::string p_path) : Service(game){
	// TODO Auto-generated constructor stub
    
    
    m_gameWindow = p_window;
    //m_screenSurface = screen;
    
    m_resourcesListPath = p_path;
    
    /*
    m_imagesDirectoryPath = path +IMAGES_DIRECTORY_SUFFIX;
    m_texturesDirectoryPath = path + TEXTURES_DIRECTORY_SUFFIX;
    m_audioDirectoryPath = path + AUDIO_DIRECTORY_SUFFIX;
    */
    
    LoadResources();
}

/** Destructor
 *  Deletes all loaded resources
 */

n8::ResourceManager::~ResourceManager() {
    Log::Info(TAG, "Destructor");
    
	map<string, Resource*>::iterator ii;
    
    for (ii=m_loadedResources.begin(); ii != m_loadedResources.end(); ii++) {
        Resource* tmp = ii->second;
        ii->second = nullptr;
        delete tmp;
    }
    
}

void n8::ResourceManager::LoadResources(){
    
    tinyxml2::XMLDocument resourcesListFile;
    tinyxml2::XMLElement* root = nullptr;
    tinyxml2::XMLElement* idElement = nullptr;
    
    resourcesListFile.LoadFile( m_resourcesListPath.c_str());
    
    root = resourcesListFile.FirstChildElement( RESOURCES_TAG.c_str() );
    
    if(root){
        // Get Images
        tinyxml2::XMLElement* imageElements = root->FirstChildElement( IMAGE_RESOURCES_TAG.c_str() );
        
        tinyxml2::XMLElement* imageElement = imageElements->FirstChildElement(IMAGE_TAG.c_str());
        for( imageElement; imageElement; imageElement = imageElement->NextSiblingElement()){
            
            idElement = imageElement->FirstChildElement(ID_TAG.c_str());
            std::string imagePath = imageElement->GetText();
            std::string imageID = idElement->GetText();
            
            Log::Debug( TAG,"Loading Image: " + imagePath + " with ID: " + imageID );
            LoadSprite(imagePath,imageID);
        }
        
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
 *  Loads an image from a specified filepath, then creates an optimzed copy of the image
 *
 *  @param filename the filename of the image to load and optimize
 *  @return a pointer to the optimized copy of the image
 */
SDL_Surface* n8::ResourceManager::LoadOptimizedImage( string filename )
{
    
    //The final optimized image
	SDL_Surface* optimizedSurface = nullptr;
    
	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( filename.c_str() );
	if( loadedSurface == nullptr )
	{
        std::string msg = "  IMG_Load failed." + filename;
		Log::Error(TAG, msg);
	}
    else
	{
        //Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface( loadedSurface, m_gameWindow->GetSurface().format, NULL );
		if( optimizedSurface == nullptr )
		{
			Log::Error(TAG, "  Failed to load optimized version of: " + filename);
		}
        else{
            Log::Debug(TAG, "  Successfully loaded optimized image");
        }
        
		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}
    
	return optimizedSurface;
}


/**
 *  Loads Sprite resources.
 */
void n8::ResourceManager::LoadSprite(std::string p_filename, std::string p_id){
    SDL_Surface* spriteImage = LoadOptimizedImage(p_filename);
    
    if(spriteImage != nullptr){
        m_loadedResources[p_id] = new Sprite(p_filename, spriteImage);
        Log::Debug(TAG, "  Successfully loaded sprite: " + p_filename);
    }
    else{
        Log::Error(TAG, "  Failed to load sprite: " + p_filename);
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
        texture = SDL_CreateTextureFromSurface( const_cast<SDL_Renderer*>(&m_gameWindow->GetRenderer()), loadedSurface );
        if( texture == nullptr )
        {
            std::string msg( "  Unable to create texture from " + p_filename + "SDL Error: " +SDL_GetError() );
            Log::Error(TAG, msg);
        }
        
        texW = loadedSurface->w;
        texH = loadedSurface->h;
        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }
    
    if (texture != nullptr) {
        m_loadedResources[p_id] = new Texture(p_filename, texture, texW, texH);
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
        m_loadedResources[p_id] = new Music(p_filename, music);
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
        m_loadedResources[p_id] = new SoundEffect(p_filename, soundEffect);
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
        m_loadedResources[p_id] = new Font(p_filename, font);
        Log::Debug(TAG, "  Successfully loaded font: " + p_filename);
    }
    else{
        
        Log::Error(TAG, "  Failed to load font: " + p_filename + "  " + TTF_GetError());
    }
    TTF_CloseFont(font);
}

/** GetResource
 *  Used to get resource object pointers from the resource manager
 *
 *  @param p_resourceID The identifier for the desired resource.  Used as the key for looking up the resource in the resource map
 *
 *  @return Pointer to a resource object matching the passed key, nullptr otherwise
 */
n8::Resource* n8::ResourceManager::GetResource(std::string p_resourceID){
    return m_loadedResources[p_resourceID];
}

void n8::ResourceManager::OnNotify(n8::Event* event){
    
}

