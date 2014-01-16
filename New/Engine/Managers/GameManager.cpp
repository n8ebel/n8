/*
 * GameManager.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            12/22/13
 * Organization:    n8Tech
 *
 */
#include <iostream>

#include "GameManager.h"
#include "StateManager.h"
#include "WindowManager.h"

using namespace std;

int GameManager::m_nextId = 0;  //static counter for unique ids



/** Default constructor
 *
 *  Initializes all values and resizes the screen to the
 *      default values
 *
 */
GameManager::GameManager(){
    if (DEBUGGING) {
        Log::Info(GAME_MANAGER, "Constructor was called");
    }
    m_fps = DEFAULT_FPS;
    m_quit = false;
    
    if (DEBUGGING) {
        Log::Info(GAME_MANAGER, "Constructor finished");
    }
}

/** Default destructor
 *
 *  Frees the background surface
 */
GameManager::~GameManager(){
    if (DEBUGGING) {
        Log::Info(GAME_MANAGER, "Destructor was called");
    }
}

/** Runs the game loop for the engine
 *
 *  Uses the quit_ flag to determine when to exit the loop
 *  Each iteration through the loop processes the current state
 */
void GameManager::RunGame(){
    
    while (m_quit == false) {
        m_currentTime = SDL_GetTicks();
        
        StateManager::GetInstance()->ProcessState(m_currentTime, WindowManager::GetInstance()->GetScreenSurface());
        
        if (StateManager::GetInstance()->GetStackSize() == 0) {
            EndGame();
        }
        
        if ( 1000/m_fps > SDL_GetTicks() - m_currentTime) {
            SDL_Delay(1000/m_fps - (SDL_GetTicks() - m_currentTime));
        }
    }

}

/** handles any operations specific to ending the game */
void GameManager::EndGame(){
    m_quit = true;
    
    Log::Info(GAME_MANAGER, "Ending Game");
}

/** Used to get the next available unique integer id for a created entity.  When called nextid_ is incremented so the return values are always unique.
 *
 *  @return The next available id number
 */
int GameManager::GetNextId(){
    m_nextId++;
    return m_nextId;
}

/** Changes the frame per second value for the game loop
 *
 *  @param newFPS The integer value for the fps value
 *
 *  @return The fps value
 */
int GameManager::SetFPS(int newFPS){
    if(newFPS > 0){
        m_fps = newFPS;
    }
    
    return m_fps;
}
