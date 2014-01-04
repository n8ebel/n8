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
#include "Values.h"

/** Default constructor */
Exit_State_Event::Exit_State_Event(){

}

/** Default destructor */
Exit_State_Event::~Exit_State_Event(){

}

/** Carries out the operations of the event */
void Exit_State_Event::process(){
    Log::debug(EXIT_STATE_EVENT, "Popping " + STATES[State_Manager::get_instance()->get_current_state_id()->get_id()]);
    State_Manager::get_instance()->pop_state();
}


