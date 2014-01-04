/*
 * Exit_State_Event.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            1/3/14
 * Organization:    n8Tech
 *
 */

#include "Exit_State_Event.h"
#include "State_Manager.h"

Exit_State_Event::Exit_State_Event(){

}

Exit_State_Event::~Exit_State_Event(){

}

void Exit_State_Event::process(){
    std::cout << "MenuState.escape" << std::endl;
    State_Manager::getInstance()->popState();
}


