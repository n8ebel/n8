/*
*  Game.cpp
*  goobar
*
*  Created by Nate Ebel on 3/18/14.
*  Copyright (c) 2014 n8Tech. All rights reserved.
*/

#include <assert.h>

#include "Game.h"

/** Default Constructor */
n8::Game::Game(){
    m_fps = DEFAULT_FPS;
    m_quit = false;
}

/** Destructor */
n8::Game::~Game(){
    
}

/** Setup
 *  Initializes default game systems and member variables
 */
void n8::Game::Setup(){
    SDL_Init( SDL_INIT_EVERYTHING );
    m_serviceManager = ServiceManager::GetInstance();
    
}

/** Shutdown
 *  Deletes registers game systems which in turn delete all other game data
 */
void n8::Game::Shutdown(){
    SDL_Quit();
}

/** Start
 *  Starts the game loop
 */
void n8::Game::Start(){
    m_timer.UpdateCurrentTime();
    while (m_quit == false) {
        
        //process state
        
        //check state stack size
        
        m_timer.SyncGame(m_fps);  //ensures proper fps
    }
}


/** Stop
 *  Stops the running game loop
 */
void n8::Game::Stop(){
    
}

/** Changes the frame per second value for the game loop
 *
 *  @param newFPS The integer value for the fps value
 *
 *  @return The fps value
 */
void n8::Game::SetFPS(unsigned newFPS){
    m_fps = newFPS;
}

/** ResizeWindow
*   Changes the dimensions of the game window
*
*   @param unsigned width The desired width of the window
*   @param unsigned height The desired height of the window
*/
void n8::Game::ResizeWindow(unsigned width, unsigned height){
    assert(&m_window);
    m_window.ResizeWindow(width,height);
}