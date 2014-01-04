/*
 * Show_Menu_Event.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            1/3/14
 * Organization:    n8Tech
 *
 */

#include "Show_Menu_Event.h"
#include "State_Manager.h"
#include "Values.h"

Show_Menu_Event::Show_Menu_Event(){
    
}

Show_Menu_Event::~Show_Menu_Event(){
    
}

void Show_Menu_Event::process(){
    State_Manager::getInstance()->pushState(MENU_STATE);
}


