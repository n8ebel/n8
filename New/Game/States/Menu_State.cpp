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

ID* Menu_State::get_id(){
    return id_;
}




void Menu_State::on_resume(){
    SDL_WM_SetCaption("Menu State", "Menu State");
}
void Menu_State::on_pause(){
    
}


void Menu_State::respond_to_user_input(){
    if(Input_Manager::get_instance()->key_is_down(SDLK_ESCAPE)){
        Event_Manager::get_instance()->queue_event(new Exit_State_Event());
    }
}

void Menu_State::update(Uint32 currentTime){
    
}

void Menu_State::render(SDL_Surface* img){
    SDL_FillRect(img, NULL, SDL_MapRGB(img->format, 0,255,0));
    SDL_Flip( img );
}

void Menu_State::register_entity(Entity* newEntity){
    
}
