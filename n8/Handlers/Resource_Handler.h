/*
 * resource_handler_.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

#include <map>
#include <string>
#include "Sprite.h"

class Resource_Handler{
    
private:
    map<string,Sprite*> loaded_images_;  /** < Stores all images loaded by the system  ***/
    
    SDL_Surface* load_image(string filename);
    
public:
    
    ~Resource_Handler();
    Resource_Handler();
    
    void load_images(string filepath);
    
    Sprite* get_sprite(string file);
    
};