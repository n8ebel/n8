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
#include <sstream>

#include "/Library/Frameworks/SDL2.framework/Versions/A/Headers/SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "tinyxml2.h"


#include "Event.h"
#include "Resource.h"

#include "Service.h"
#include "Texture.h"
#include "Music.h"
#include "SoundEffect.h"
#include "Font.h"
#include "Window.h"

//class Resource;

namespace n8{
    /** \class ResourceManager
     *  \brief Loads and stores game resources
     *
     *  Loads resource information from an xml file.  Attempts to load all
     *    specified data and store the neccessary resource objects using
     *    unique keys for lookup.  The user can then request pointers to
     *    resource objects when needed.
     */
    class ResourceManager : public Service{
    public:
        ResourceManager(std::shared_ptr<n8::Game>, std::shared_ptr<n8::Window> p_window, std::string p_path);
        ~ResourceManager();
        
        const std::shared_ptr<Texture>& GetTexture(std::string) const;
        const std::shared_ptr<Music>& GetMusic(std::string) const;
        const std::shared_ptr<SoundEffect>& GetSoundEffect(std::string) const;
        const std::shared_ptr<Font>& GetFont(std::string) const;

        
        void OnNotify(std::shared_ptr<Event>) override;
        
    private:
        const std::string RESOURCES_TAG = "Resources";
        const std::string TEXTURE_RESOURCES_TAG = "TextureResources";
        const std::string SOUND_EFFECT_RESOURCES_TAG = "SoundEffectResources";
        const std::string MUSIC_RESOURCES_TAG = "MusicResources";
        const std::string FONT_RESOURCES_TAG = "FontResources";
        
        const std::string TEXTURE_TAG = "Texture";
        const std::string SOUND_EFFECT_TAG = "SoundEffect";
        const std::string MUSIC_TAG = "Music";
        const std::string FONT_TAG = "Font";
        
        const std::string SIZE_TAG = "Size";
        const std::string ID_TAG = "ID";
        
        const std::string RESOURCE_DIRECTORIES_PREFIX = "Resources";
        const std::string TEXTURES_DIRECTORY_SUFFIX = "Textures";
        const std::string SOUND_EFFECT_DIRECTORY_SUFFIX = "SoundEffect";
        const std::string MUSIC_DIRECTORY_SUFFIX = "Music";
        const std::string FONT_DIRECTORY_SUFFIX = "Font";
        
        std::string m_resourcesListPath; /**< Filepath to the resource list */
        
        std::map<std::string, std::shared_ptr<Texture> > m_loadedTextures;
        std::map<std::string, std::shared_ptr<Music> > m_loadedMusic;
        std::map<std::string, std::shared_ptr<SoundEffect> > m_loadedSoundEffects;
        std::map<std::string, std::shared_ptr<Font> > m_loadedFonts;
        
        std::shared_ptr<n8::Window> m_gameWindow;
        
        SDL_Surface* LoadOptimizedImage(std::string filename);
        
        void LoadResources();
        void LoadTexture(std::string, std::string);
        void LoadMusic(std::string, std::string);
        void LoadSoundEffect(std::string, std::string);
        void LoadFont(std::string, std::string,int);
    };
}

#endif /* defined(RESOURCE_MANAGER_SERVICE_H) */
