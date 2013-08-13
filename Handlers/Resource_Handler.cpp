/*
 * resource_handler_.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

#include "Resource_Handler.h"
//#include "Sprite.h"
//#include "n8.h"
#include <map>
#include <string>
#include <fstream>
#include <iostream>

class n8;

/** Default Destructor
 *  Deletes all loaded resources including images and sound files
 *
 */
Resource_Handler::~Resource_Handler(){
    
    map<string, Sprite*>::iterator ii;
    
    for (ii=loaded_images_.begin(); ii != loaded_images_.end(); ii++) {
        delete ii->second;
    }
}

/** Default Constructor **/
Resource_Handler::Resource_Handler(){
    
}

/** 
 *  Loads an image from a specified filepath, then creates an optimzed copy of the image
 *
 *  @param filename the filename of the image to load and optimize
 *  @return a pointer to the optimized copy of the image
 */
SDL_Surface* Resource_Handler::load_image( string filename ) 
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
void Resource_Handler::load_images(string filepath){
    cout << "Loading Images" << endl;
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
            Sprite* tmp = new Sprite(inputfile,img);
            loaded_images_[inputfile] = tmp;
        }
    }
}

/** 
 *  Used to return a pointer to a specified sprite object
 *
 *  @param file the filename of the image stored in the desired sprite object
 *  @return a pointer to the desired sprite object or NULL if it doesn't exist
 */
Sprite* Resource_Handler::get_sprite(string file){
    cout << "file: " << file << endl;
    map<string,Sprite*>::iterator ia;
    for (ia = loaded_images_.begin(); ia != loaded_images_.end(); ia++) {
        cout << ia->second << endl;
    }

    map<string,Sprite*>::iterator ii = loaded_images_.find(file);
    if ( ii != loaded_images_.end()) {
        return ii->second;
    }
    else{
        return NULL;
    }
}