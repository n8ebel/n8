/*
 *  ResourceManagerService.cpp
 *  goobar
 *
 *  Created by Nate Ebel on 3/21/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#include <fstream>

#include "ResourceManagerService.h"
#include "Log.h"

#define TAG "ResourceManagerService"

n8::ResourceManagerService::ResourceManagerService(Game* game, SDL_Surface* screen) : Service(game){
	// TODO Auto-generated constructor stub
    
    m_screenSurface = screen;
}

/** Destructor
 *  Deletes all loaded resources
 */

n8::ResourceManagerService::~ResourceManagerService() {
    Log::Info(TAG, "Destructor");
    
	map<string, SDL_Surface*>::iterator ii;
    
    for (ii=m_loadedSprites.begin(); ii != m_loadedSprites.end(); ii++) {
        SDL_FreeSurface(ii->second);
    }
}

/**
 *  Loads an image from a specified filepath, then creates an optimzed copy of the image
 *
 *  @param filename the filename of the image to load and optimize
 *  @return a pointer to the optimized copy of the image
 */
SDL_Surface* n8::ResourceManagerService::LoadImage( string filename )
{
    
    /*
    //Temporary storage for the image that's loaded
    SDL_Surface* loadedImage = NULL;
    
    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;
    
    //Load the image
    
    loadedImage = IMG_Load( filename.c_str() );
    
    
    //If nothing went wrong in loading the image
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormatAlpha( loadedImage );
        assert(optimizedImage);
        
        Log::Debug(TAG, "  Successfully loaded optimized image");
        
        //Free the old image
        SDL_FreeSurface( loadedImage );
    }
    else{
        Log::Error(TAG, "SDL_LoadBMP failed");
    }
    
    
    //Return the optimized image
    return optimizedImage;
     
     */
    
    //The final optimized image
	SDL_Surface* optimizedSurface = NULL;
    
	//Load image at specified path
	SDL_Surface* loadedSurface = SDL_LoadBMP( filename.c_str() );
	if( loadedSurface == NULL )
	{
        std::string msg = "SDL_LoadBMP failed." + filename;
		Log::Error(TAG, msg);
	}
    else
	{
        Log::Debug(TAG, "  Successfully loaded optimized bmp");
		
        //Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface( loadedSurface, m_screenSurface->format, NULL );
		if( optimizedSurface == NULL )
		{
			Log::Error(TAG, "Failed to load optimized version of: " + filename);
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
void n8::ResourceManagerService::LoadImagesFromFile(string filepath){
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
                m_loadedSprites[inputfile] = img;
            }
            else {
                Log::Error(TAG, "Failed to load optimized image" + inputfile);
            }
            
        }
    }
    else{
        Log::Error(TAG, "Failed to open input file");
    }
    
    
}

void n8::ResourceManagerService::OnNotify(n8::Event* event){
    
}