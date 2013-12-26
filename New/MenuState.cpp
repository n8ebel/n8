/*
 * MenuState.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            12/22/13
 * Organization:    n8Tech
 *
 */

#include "MenuState.h"
#include "State_Manager.h"
#include <iostream>

using namespace std;


MenuState::MenuState()  {
    id_ = new ID(0);
    
}

MenuState::~MenuState(){
    
}

ID* MenuState::getID(){
    return id_;
}

void MenuState::start(){
    
}

void MenuState::processInput(){
    while(InputManager::getInstance()->handle_event()){
        if(InputManager::getInstance()->key_is_down(SDLK_ESCAPE)){
            std::cout << "MenuState.escape" << std::endl;
            State_Manager::getInstance()->popState();
        }
    
        if(InputManager::getInstance()->key_is_down(SDLK_SPACE)){
            State_Manager::getInstance()->changeState(1);
        }
   }
    
}

void MenuState::update(Uint32 currentTime){
    //std::cout << "MenuState.update()" << std::endl;
}
void MenuState::render(SDL_Surface* img){
    //std::cout << "MenuState.render()" << std::endl;
    SDL_FillRect(img, NULL, SDL_MapRGB(img->format, 0,255,0));
    SDL_Flip( img );
}
