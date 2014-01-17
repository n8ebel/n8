/*
 * Exit_State_Event.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            1/3/14
 * Organization:    n8Tech
 *
 */

#include "ExitStateEvent.h"
#include "StateManager.h"
#include "Values.h"

/** Default constructor */
ExitStateEvent::ExitStateEvent(){

}

/** Default destructor */
ExitStateEvent::~ExitStateEvent(){

}

/** Pops the current state off of the state stack */
void ExitStateEvent::Process(){
    Log::Debug(EXIT_STATE_EVENT, "Popping " + STATES[StateManager::GetInstance()->GetCurrentStateId()->GetId()]);
    StateManager::GetInstance()->PopState();
}


