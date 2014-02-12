/*
 * Event_Manager.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            1/14/14
 * Organization:    n8Tech
 *
 */

#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include "Object.h"
#include "Singleton.h"
#include "Sprite.h"

#include <map>
#include <string>
#include <iostream>
#include <fstream>



class ResourceManager : public Singleton<ResourceManager>, Object {
public:
    
    ResourceManager() ;
    ~ResourceManager();
    
    void LoadImages(string filepath);
    Sprite* GetSprite(string file);

private:
    map<string,Sprite*> m_loadedSprites;  /** < Stores all images loaded by the system  ***/
    SDL_Surface* LoadImage(string filename);
};


#endif
