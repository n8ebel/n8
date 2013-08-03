/*
 * cResource_Handler.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

#include "cResource_Handler.h"
#include "cSprite.h"
#include <map>
#include <string>
#include <fstream>
#include <iostream>

cResource_Handler::~cResource_Handler(){
    
    map<string, cSprite*>::iterator ii;
    
    for (ii=loaded_images.begin(); ii != loaded_images.end(); ii++) {
        delete ii->second;
    }
}

cResource_Handler::cResource_Handler(){
    
}

SDL_Surface* cResource_Handler::load_image( string filename ) 
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

void cResource_Handler::load_images(string filepath){
    ifstream inFile;
    inFile.open(filepath.c_str());
    if (inFile.is_open()) {
        while (!inFile.eof()) {
            string inputfile;
            inFile >> inputfile;
            std::cout << inputfile << endl;
            SDL_Surface* img = load_image(inputfile);
            if (img == NULL) {
                cout << "Failed to load: " << inputfile << endl;
            }
            cSprite* tmp = new cSprite(inputfile,img);
            loaded_images[inputfile] = tmp;
        }
    }
}

cSprite* cResource_Handler::get_sprite(string file){
    return loaded_images[file];
}