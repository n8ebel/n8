/*
 *  Game.h
 *  goobar
 *
 *  Created by Nate Ebel on 3/18/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <sstream>
/*
#include "SDL/SDL.h"
#include "SDL_image/SDL_image.h"
#include "SDL_mixer/SDL_mixer.h"
*/
#include <SDL2/SDL.h>
#include "SDL2_image/SDL_image.h"
#include "SDL2_mixer/SDL_mixer.h"
#include "SDL2_ttf/SDL_ttf.h"
#include "tinyxml2.h"

#include "ServiceManager.h"
#include "Log.h"
#include "RenderService.h"
#include "AudioService.h"
#include "InputService.h"
#include "StateManagerService.h"
//#include "ResourceManager.h"
#include "ResourceManager.h"
#include "State.h"
#include "Timer.h"
#include "Window.h"



namespace n8 {
    
class Game{
public:
    static const int DEFAULT_FPS = 60;
    
    static void Init();
    static void Shutdown();
    
    Game(const char*);
    ~Game();
    
    void Setup();
    void Start();
    void Stop();
    
    void SetFPS(unsigned);
    void DefineWindowSize(unsigned, unsigned);
    
    void RegisterState(EState::Values, State*);
    void SetStartState(EState::Values);
private:
    const std::string RESOURCE_FILE_SUFFIX = "Resources.xml";;
    
    ServiceManager* m_serviceManager;
    n8::Window m_window;
    n8::Timer m_timer;
     
    
    int m_fps;  /** < value to control game loop speed **/
    bool m_quit;  /** < flag to control when game loop ends **/
    
    unsigned m_windowWidth;
    unsigned m_windowHeight;
    
    std::string m_configPath;
    std::string m_directoryPath;
    std::string m_resourcesListPath;
    
    void ProcessConfigFile();
    
    void InitializeDirectoryPath();
    void InitializeResourcesPath();
    
};

}

#endif /* defined(GAME_H) */
