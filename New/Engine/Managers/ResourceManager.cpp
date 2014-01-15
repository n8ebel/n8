/*
 * Event_Manager.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            1/14/14
 * Organization:    n8Tech
 *
 */

#include "ResourceManager.h"




ResourceManager::ResourceManager() {
	// TODO Auto-generated constructor stub
    
}

ResourceManager::~ResourceManager() {
    Log::Info(RESOURCE_MANAGER, "Destructor");
    
	map<string, Sprite*>::iterator ii;
    
    for (ii=m_loadedSprites.begin(); ii != m_loadedSprites.end(); ii++) {
        delete ii->second;
    }
}

/**
 *  Loads an image from a specified filepath, then creates an optimzed copy of the image
 *
 *  @param filename the filename of the image to load and optimize
 *  @return a pointer to the optimized copy of the image
 */
SDL_Surface* ResourceManager::LoadImage( string filename )
{
    //Temporary storage for the image that's loaded
    SDL_Surface* loadedImage = NULL;
    
    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;
    
    //Load the image
    
    loadedImage = SDL_LoadBMP( filename.c_str() );
    
    
    
    //If nothing went wrong in loading the image
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );
        
        //Free the old image
        SDL_FreeSurface( loadedImage );
    }
    
    //Return the optimized image
    return optimizedImage;
}

/**
 *  Parses an input file containing image filepaths, loads those images, and stores them in a map
 *
 *  @param filepath the filepath for the configuration file containing all image filenames to load
 */
void ResourceManager::LoadImages(string filepath){
    cout << "Loading Images" << endl;
    ifstream inFile;
    inFile.open(filepath.c_str());
    if (inFile.is_open()) {
        while (!inFile.eof()) {
            string inputfile;
            inFile >> inputfile;
            std::cout << inputfile << endl;
            SDL_Surface* img = LoadImage(inputfile);
            if (img == NULL) {
                cout << "Failed to load: " << inputfile << endl;
            }
            Sprite* tmp = new Sprite(inputfile,img);
            m_loadedSprites[inputfile] = tmp;
        }
    }
}

/**
 *  Used to return a pointer to a specified sprite object
 *
 *  @param file the filename of the image stored in the desired sprite object
 *  @return a pointer to the desired sprite object or NULL if it doesn't exist
 */
Sprite* ResourceManager::GetSprite(string file){
    cout << "file: " << file << endl;
    map<string,Sprite*>::iterator ia;
    for (ia = m_loadedSprites.begin(); ia != m_loadedSprites.end(); ia++) {
        cout << ia->second << endl;
    }
    
    map<string,Sprite*>::iterator ii = m_loadedSprites.find(file);
    if ( ii != m_loadedSprites.end()) {
        return ii->second;
    }
    else{
        return NULL;
    }
}
