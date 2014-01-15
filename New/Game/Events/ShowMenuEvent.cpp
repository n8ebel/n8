/*
 * Show_Menu_Event.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            1/3/14
 * Organization:    n8Tech
 *
 */

#include "ShowMenuEvent.h"
#include "StateManager.h"
#include "Values.h"

/** Default constructor */
ShowMenuEvent::ShowMenuEvent(){
    
}

/** Default destructor */
ShowMenuEvent::~ShowMenuEvent(){
    
}

/** Carries out the operations of the event */
void ShowMenuEvent::Process(){
    Log::Debug(MENU_STATE_EVENT, "Showing " + STATES[MENU_STATE]);
    StateManager::GetInstance()->PushState(MENU_STATE);
}


