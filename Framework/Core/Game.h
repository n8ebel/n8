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
/*
#include "SDL/SDL.h"
#include "SDL_image/SDL_image.h"
#include "SDL_mixer/SDL_mixer.h"
*/
#include <SDL2/SDL.h>
#include "SDL2_image/SDL_image.h"
#include "SDL2_mixer/SDL_mixer.h"
#include "SDL2_ttf/SDL_ttf.h"

#include "ServiceManager.h"
#include "Log.h"
#include "InputService.h"
#include "StateManagerService.h"
#include "ResourceManagerService.h"
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
    
    Game();
    ~Game();
    
    void Setup();
    void Start();
    void Stop();
    
    void SetFPS(unsigned);
    void DefineWindowSize(unsigned, unsigned);
    
    void RegisterState(EState::Values, State*);
    void SetStartState(EState::Values);
private:
    
    ServiceManager* m_serviceManager;
    n8::Window m_window;
    n8::Timer m_timer;
     
    
    int m_fps;  /** < value to control game loop speed **/
    bool m_quit;  /** < flag to control when game loop ends **/
    
    unsigned m_windowWidth;
    unsigned m_windowHeight;
    
    char* m_directoryPath;
    
    void InitializeDirectoryPath();
    
};

}

#endif /* defined(GAME_H) */
