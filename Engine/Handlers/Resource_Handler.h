/*
 * resource_handler_.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

#ifndef RESOURCE_HANDLER_H
#define RESOURCE_HANDLER_H

#include <map>
#include <string>

#include "Sprite_Manager.h"


/** Handles the loading and storage of gfx and sfx resources.
 *  The required resources are read from configuration files and are loaded, optimized, and stored in a map.
 *  Assets can be accessed by using there unique identifiers.  These identifiers should either be the filename,
 *  or the absolute filepath of the asset.  Created entities can access the resources they need by storing
 *  pointers to objects held in the resource handler.
 */
class Resource_Handler{
public:
    ~Resource_Handler();
    Resource_Handler();
    
    void load_images(string filepath);
    Sprite* get_sprite(string file);
    
private:
    //map<string,Sprite*> loaded_images_;  /** < Stores all images loaded by the system  ***/

    //SDL_Surface* load_image(string filename);

    Sprite_Manager* sprite_manager_;


};

#endif
