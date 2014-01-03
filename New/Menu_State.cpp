/*
 * MenuState.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            12/22/13
 * Organization:    n8Tech
 *
 */

#include "Menu_State.h"
#include "State_Manager.h"
#include <iostream>

using namespace std;


Menu_State::Menu_State()  {
    id_ = new ID(0);
    
}

Menu_State::~Menu_State(){
    
}

ID* Menu_State::getID(){
    return id_;
}

void Menu_State::start(){
    
}

void Menu_State::respondToUserInput(){
    while(Input_Manager::getInstance()->handle_event()){
        if(Input_Manager::getInstance()->key_is_down(SDLK_ESCAPE)){
            std::cout << "MenuState.escape" << std::endl;
            State_Manager::getInstance()->popState();
        }
    
        if(Input_Manager::getInstance()->key_is_down(SDLK_SPACE)){
            State_Manager::getInstance()->pushState(1);
        }
   }
    
}

void Menu_State::update(Uint32 currentTime){
    //std::cout << "MenuState.update()" << std::endl;
}
void Menu_State::render(SDL_Surface* img){
    //std::cout << "MenuState.render()" << std::endl;
    SDL_FillRect(img, NULL, SDL_MapRGB(img->format, 0,255,0));
    SDL_Flip( img );
}
