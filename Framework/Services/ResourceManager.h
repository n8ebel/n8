/*
 *  ResourceManagerService.h
 *  goobar
 *
 *  Created by Nate Ebel on 3/21/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <iostream>
#include <string>
#include <map>

#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"

#include "Service.h"
#include "Event.h"

class Resource;

namespace n8{
    class ResourceManager : public Service{
    public:
        ResourceManager(SDL_Surface* screen, char* path);
        ~ResourceManager();
        
        Resource* GetResource(std::string);
        
        void LoadImagesFromFile(std::string filepath);
        SDL_Surface* LoadImage(std::string filename);
        
        void OnNotify(Event*);
        
    private:
        const std::string RESOURCE_DIRECTORIES_PREFIX = "Resources";
        const std::string IMAGES_DIRECTORY_SUFFIX = "Images";
        const std::string TEXTURES_DIRECTORY_SUFFIX = "Textures";
        const std::string AUDIO_DIRECTORY_SUFFIX = "Audio";
        
        std::string m_imagesDirectoryPath;
        std::string m_texturesDirectoryPath;
        std::string m_audioDirectoryPath;
        
        std::map<std::string,Resource*> m_loadedResources;  /** < Stores all images loaded by the system  ***/
        SDL_Surface* m_screenSurface;
        
        void LoadResources();
        void LoadImages();
        void LoadTextures();
        void LoadAudio();
    };
}

#endif /* defined(RESOURCE_MANAGER_SERVICE_H) */
