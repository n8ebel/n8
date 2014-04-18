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

n8::ResourceManager::ResourceManager(SDL_Surface* screen, std::string path) {
	// TODO Auto-generated constructor stub
    
    
    m_screenSurface = screen;
    
    m_resourcesListPath = path;
    m_imagesDirectoryPath = path +IMAGES_DIRECTORY_SUFFIX;
    m_texturesDirectoryPath = path + TEXTURES_DIRECTORY_SUFFIX;
    m_audioDirectoryPath = path + AUDIO_DIRECTORY_SUFFIX;
    
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
        ii->second = NULL;
        delete tmp;
    }
    
}

void n8::ResourceManager::LoadResources(){
    
    tinyxml2::XMLDocument resourcesListFile;
    tinyxml2::XMLElement* root = NULL;
    
    resourcesListFile.LoadFile( m_resourcesListPath.c_str());
    
    root = resourcesListFile.FirstChildElement( RESOURCES_TAG.c_str() );
    
    if(root){
        // Get Images
        tinyxml2::XMLElement* imageElements = root->FirstChildElement( IMAGE_RESOURCES_TAG.c_str() );
        
        tinyxml2::XMLElement* imageElement = imageElements->FirstChildElement(IMAGE_TAG.c_str());
        for( imageElement; imageElement; imageElement = imageElement->NextSiblingElement()){
            std::string imagePath = imageElement->GetText();
            Log::Debug( TAG,"Loading Image: " + imagePath );
            
            
             LoadSprite(imagePath);
             
        }
        
        // Get Audio
        tinyxml2::XMLElement* audioElements = root->FirstChildElement( AUDIO_RESOURCES_TAG.c_str() );
        
        tinyxml2::XMLElement* audioElement = audioElements->FirstChildElement(AUDIO_TAG.c_str());
        for( audioElement; audioElement; audioElement = audioElement->NextSiblingElement()){
            std::string audioPath = audioElement->GetText();
            Log::Debug(TAG, "Loading SoundEffect: " + audioPath );
            
            
            LoadSoundEffect(audioPath);
            
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
	SDL_Surface* optimizedSurface = NULL;
    
	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( filename.c_str() );
	if( loadedSurface == NULL )
	{
        std::string msg = "  IMG_Load failed." + filename;
		Log::Error(TAG, msg);
	}
    else
	{
        //Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface( loadedSurface, m_screenSurface->format, NULL );
		if( optimizedSurface == NULL )
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
 *  Parses an input file containing image filepaths, loads those images, and stores them in a map
 *
 *  @param filepath the filepath for the configuration file containing all image filenames to load
 */
void n8::ResourceManager::LoadImagesFromFile(string filepath){
    /*
    Log::Debug(TAG, "Loading Images");
    ifstream inFile;
    inFile.open(filepath.c_str());
    if (inFile.is_open()) {
        while (!inFile.eof()) {
            string inputfile;
            inFile >> inputfile;
            Log::Debug(TAG, "  Loading optimized version of: " + inputfile);
            SDL_Surface* img = LoadImage(inputfile);
            
            if (img) {
                m_loadedResources[inputfile] = img;
            }
            else {
                Log::Error(TAG, "Failed to load optimized image" + inputfile);
            }
            
        }
    }
    else{
        Log::Error(TAG, "Failed to open input file");
    }
    */
    
}

/**
 *  Loads Sprite resources.  Currently not implemented.
 */
void n8::ResourceManager::LoadSprite(std::string p_filename){
    SDL_Surface* spriteImage = LoadOptimizedImage(p_filename);
    
    if(spriteImage != NULL){
        m_loadedResources[p_filename] = new Sprite(p_filename, spriteImage);
    }
}

/** 
 *  Loads Texture resources.  Currently not implemented
 */
void n8::ResourceManager::LoadTexture(){
    
}

/**
 *  Loads Audio resources.  Currently not implemented.
 */
void n8::ResourceManager::LoadSoundEffect(std::string p_filename){
    Mix_Chunk* soundEffect = Mix_LoadWAV(p_filename.c_str());
    
    if(soundEffect != NULL){
        m_loadedResources[p_filename] = new SoundEffect(p_filename, soundEffect);
        Log::Debug(TAG, "  Successfully loaded sound effect");
    }
    else{
        Log::Error(TAG, "  Failed to load sound effect");
    }
    
    Mix_PlayChannel( -1, soundEffect, 0 );
}

/**
 *  Loads font resources.  Currently not implemented.
 */
void n8::ResourceManager::LoadFont(){
    
}

n8::Resource* n8::ResourceManager::GetResource(std::string p_resourceID){
    return m_loadedResources[p_resourceID];
}

void n8::ResourceManager::OnNotify(n8::Event* event){
    
}

