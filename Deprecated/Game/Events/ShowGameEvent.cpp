/*
 * ShowGameEvent.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            1/3/14
 * Organization:    n8Tech
 *
 */

#include "ShowGameEvent.h"
#include "StateManager.h"
#include "Values.h"

/** Default constructor */
ShowGameEvent::ShowGameEvent(){
    
}

/** Default destructor */
ShowGameEvent::~ShowGameEvent(){
    
}

/** Carries out the operations of the event */
void ShowGameEvent::Process(){
    Log::Debug(GAME_STATE_EVENT, "Showing " + STATES[GAME_STATE]);
    StateManager::GetInstance()->PushState(GAME_STATE);
}


