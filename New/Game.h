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

#include "SDL/SDL.h"
#include "SDL_image/SDL_image.h"

#include "ServiceManager.h"
#include "Timer.h"
#include "Window.h"

namespace n8 {
    
class Game{
public:
    static const int DEFAULT_FPS = 60;
    
    Game();
    ~Game();
    
    void Setup();
    void Shutdown();
    void Start();
    void Stop();
    
    void SetFPS(unsigned);
    void ResizeWindow(unsigned, unsigned);
    
private:
    
    ServiceManager* m_serviceManager;
    n8::Window m_window;
    n8::Timer m_timer;
     
    
    int m_fps;  /** < value to control game loop speed **/
    bool m_quit;  /** < flag to control when game loop ends **/
    
};

}

#endif /* defined(GAME_H) */
