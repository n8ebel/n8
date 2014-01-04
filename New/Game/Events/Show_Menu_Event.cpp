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

/** Default constructor */
Show_Menu_Event::Show_Menu_Event(){
    
}

/** Default destructor */
Show_Menu_Event::~Show_Menu_Event(){
    
}

/** Carries out the operations of the event */
void Show_Menu_Event::process(){
    Log::debug(MENU_STATE_EVENT, "Showing " + STATES[MENU_STATE]);
    State_Manager::get_instance()->push_state(MENU_STATE);
}


