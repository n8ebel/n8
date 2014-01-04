//
//  main.cpp
//  goobar
//
//  Created by Nate Ebel on 12/22/13.
//  Copyright (c) 2013 n8Tech. All rights reserved.
//


#include "n8.h"

#include "Game_State.h"
#include "Menu_State.h"

#include "Values.h"

#include <iostream>

using namespace std;



int main(int argc, char* argv[]){
    //SDL_Init( SDL_INIT_EVERYTHING );
    
    
    if(n8::setup_n8()){
    
        Game_Manager* game = Game_Manager::get_instance();
    
        game->set_caption("n8");
        
        State_Manager::get_instance()->register_state(GAME_STATE, new Game_State());
        State_Manager::get_instance()->register_state(MENU_STATE, new Menu_State());
        
        State_Manager::get_instance()->push_state(GAME_STATE);
        
        
        game->run_game();
        
        n8::shutdown_n8();
    }
    
    
    
    
    SDL_Quit();
    return 0;
}
