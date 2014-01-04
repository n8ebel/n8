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
#include "Event_Manager.h"
#include "Exit_State_Event.h"


#include <iostream>

using namespace std;


Menu_State::Menu_State()  {
    id_ = new ID(MENU_STATE);
    
}

Menu_State::~Menu_State(){
    
}

ID* Menu_State::getID(){
    return id_;
}




void Menu_State::on_resume(){
    SDL_WM_SetCaption("Menu State", "Menu State");
}
void Menu_State::on_pause(){
    
}


void Menu_State::respondToUserInput(){
    if(Input_Manager::getInstance()->key_is_down(SDLK_ESCAPE)){
        Event_Manager::getInstance()->queueEvent(new Exit_State_Event());
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
