/*
 * GameState.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            12/22/13
 * Organization:    n8Tech
 *
 */

#include "Game_State.h"
#include "State_Manager.h"

#include <iostream>

using namespace std;

Game_State::Game_State()  {
    id_ = new ID(0);
    
}

Game_State::~Game_State(){
    
}

ID* Game_State::getID(){
    return id_;
}

void Game_State::start(){
    
}

void Game_State::processInput(){
    while(Input_Manager::getInstance()->handle_event()){
        if(Input_Manager::getInstance()->key_is_down(SDLK_ESCAPE)){
            State_Manager::getInstance()->popState();
        }
    }
    
    
}

void Game_State::update(Uint32 currentTime){
   // std::cout << "GameState.update()" << std::endl;
}
void Game_State::render(SDL_Surface* img){
    //std::cout << "GameState.render()" << std::endl;
    SDL_FillRect(img, NULL, SDL_MapRGB(img->format, 255,0,0));
    SDL_Flip( img );
}
