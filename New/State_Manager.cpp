/*
 * State_Manager.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            12/22/13
 * Organization:    n8Tech
 *
 */

#include <assert.h>
#include "State_Manager.h"
#include "n8.h"
#include "Log.h"

/** Pointer to single, static State_Manager pointer
 */
State_Manager* State_Manager::instance_ = NULL;


/** Virtual destructor
 *  Deletes registered game states
 */
State_Manager::~State_Manager(){
    Log::info(STATE_MANAGER, "Destructor was called");
    while (stateStack.size() > 0) {
        State* curState = stateStack.top();
        stateStack.pop();
        delete curState;
    }
}

/** Singleton access method.
 *
 *
 * @return Pointer to the singleton State_Manager instance
 */
State_Manager* State_Manager::getInstance(){
    if (instance_) {
        return instance_;
    }
    else{
        instance_ = new State_Manager();
        return instance_;
    }
}

/** Default constructor
 */
State_Manager::State_Manager(){
    
}

/** Stores a pointer to a State subclass in a map.
 *  If there are no states currently in the state stack,
 *    the state being added is pushed onto the stack.
 *  If a state with the specified identifier has previously
 *    been added, the new state is not added to the map.
 *
 *  @param identifier An integer identifier for the state.  Used to differentiate states
 *          and to change states.
 *  @param state A pointer to a State subcalss object
 *
 *  @return True if the state was succesffuly stored in the map; False otherwise.
 */
bool State_Manager::registerState(int identifier, State* state){
    map<int, State*>::iterator ii = registeredStates_.find(identifier);
    
    if(ii == registeredStates_.end()){
        registeredStates_[identifier] = state;
        
        if(registeredStates_.size() == 1){
            
            stateStack.push(state);
        }
        return true;
    }
    else{
        
        
        return false;
    }
    
    
    
}

/** Pushes a new State pointer onto the state stack.
 *  If the identifier hasn't been registered with the system
 *    nothing is pushed onto the stack.
 *
 *  @param identifier The map key for a stored State pointer
 *
 *  @return True if a State was pushed onto the stack, false otherwise.
 *
 */
bool State_Manager::changeState(int identifier){
    map<int, State*>::iterator ii = registeredStates_.find(identifier);
    
    if(ii != registeredStates_.end()){
        
        stateStack.push( ii->second);
        
        return true;
    }
    else{
        
        return false;
    }

}

/** If the state stack isn't empty, the top state is popped off
 *
 */
 
void State_Manager::popState(){
    if (stateStack.size() > 0) {
        stateStack.pop();
    }
}

/** Returns the size of the state stack
 *
 *  @return The integer size of the state stack
 */
int State_Manager::getStackSize(){
    return stateStack.size();
}

/** Processes a state by handling input events, updating the state logic, 
 *    and rendering the state
 *
 *  @param time The current system time
 *  @param screen The screen canvas for rendering
 *
 */
void State_Manager::processState(Uint32 time, SDL_Surface* screen){
    
    if(time > 0 && screen){
    
        if(stateStack.size() > 0){
            stateStack.top()->processInput();
        }
        
        if(stateStack.size() > 0){
            stateStack.top()->update(time);
        }
        
        if(stateStack.size() > 0){
            stateStack.top()->render(screen);
        }
    }
    else if(time <= 0){
        Log::error(STATE_MANAGER + ".processState", "Game time not greater than 0");
    }
    else if(screen == NULL){
        Log::error(STATE_MANAGER + ".processState", "Screen pointer is NULL");
    }
}