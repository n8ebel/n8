/*
 * GameState.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            12/22/13
 * Organization:    n8Tech
 *
 */

#include "GameState.h"
#include "State_Manager.h"

#include <iostream>

using namespace std;

GameState::GameState()  {
    id_ = new ID(0);
    
}

GameState::~GameState(){
    
}

ID* GameState::getID(){
    return id_;
}

void GameState::start(){
    
}

void GameState::processInput(){
    if(InputManager::getInstance()->key_is_down(SDLK_ESCAPE)){
        State_Manager::getInstance()->popState();
    }
    
}

void GameState::update(Uint32 currentTime){
   // std::cout << "GameState.update()" << std::endl;
}
void GameState::render(SDL_Surface* img){
    //std::cout << "GameState.render()" << std::endl;
    SDL_FillRect(img, NULL, SDL_MapRGB(img->format, 255,0,0));
    SDL_Flip( img );
}
