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
#include "Event_Manager.h"
#include "Exit_State_Event.h"
#include "Show_Menu_Event.h"

#include <iostream>

using namespace std;

Game_State::Game_State()  {
    id_ = new ID(GAME_STATE);
    
}

Game_State::~Game_State(){
    
}

ID* Game_State::get_id(){
    return id_;
}



void Game_State::on_resume(){
    SDL_WM_SetCaption("Game State", "Game State");
}
void Game_State::on_pause(){
    
}


void Game_State::respond_to_user_input(){
    if(Input_Manager::get_instance()->key_is_down(SDLK_ESCAPE)){
        Event_Manager::get_instance()->queue_event(new Exit_State_Event());
    }
    
    if(Input_Manager::get_instance()->key_is_down(SDLK_SPACE)){
        Event_Manager::get_instance()->queue_event(new Show_Menu_Event());
    }
}

void Game_State::update(Uint32 currentTime){
   
}
void Game_State::render(SDL_Surface* img){
    SDL_FillRect(img, NULL, SDL_MapRGB(img->format, 255,0,0));
    SDL_Flip( img );
}

void Game_State::register_entity(Entity* newEntity){
    
}
