/*
 * cResource_Handler.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

#include <map>
#include <string>
#include "cSprite.h"

class cResource_Handler{
    
private:
    map<string,cSprite*> loaded_images;
    SDL_Surface* load_image(string filename);
    
public:
    
    ~cResource_Handler();
    cResource_Handler();
    
    void load_images(string filepath);
    
    cSprite* get_sprite(string file);
    
};