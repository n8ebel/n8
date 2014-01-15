/*
 * n8.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

#include "n8.h"
#include "GameManager.h"
#include "StateManager.h"
#include "EventManager.h"
#include "InputManager.h"

#include <iostream>
#include <string>
#include <sstream>


using namespace std;

/* Default Constructor
 * 
*/ 
n8::n8(){
    
}


/** Initializes SDL 
 *
 *  @return True if SDL was initialized properly, False otherwise
 */
bool n8::Setup(){
    if (SDL_Init( SDL_INIT_EVERYTHING ) == 0){
        GameManager::Create();
        StateManager::Create();
        InputManager::Create();
        EventManager::Create();
        ResourceManager::Create();
        ResourceManager::GetInstance()->LoadImages("/Users/lcballa44/Projects/n8/Deprecated/Assets/gfx/images.txt");
        
        return true;
    }
    else{
        return false;
    }
}

/** Deletes all game systems 
 *
 *  @return True
 */
bool n8::Shutdown(){
    ResourceManager::Destroy();
    return true;
}



