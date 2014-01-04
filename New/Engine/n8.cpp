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
#include "Game_Manager.h"
#include "State_Manager.h"
#include "Event_Manager.h"
#include "Input_Manager.h"

#include <iostream>
#include <string>
#include <sstream>


using namespace std;

/* Default Constructor
 * 
*/ 
n8::n8(){
    
}



bool n8::setup_n8(){
    if (SDL_Init( SDL_INIT_EVERYTHING ) == 0){
        return true;
    }
    else{
        return false;
    }
}


bool n8::shutdown_n8(){
    delete Input_Manager::get_instance();
    delete State_Manager::get_instance();
    delete Game_Manager::get_instance();
    delete Event_Manager::get_instance();
    
    return true;
}



