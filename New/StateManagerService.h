/*
 * StateManagerService.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            3/19/14
 * Organization:    n8Tech
 *
 */

#ifndef STATE_MANAGER_SERVICE_H
#define STATE_MANAGER_SERVICE_H

#include <map>
#include <stack>

#include "SDL/SDL.h"
#include "ID.h"
#include "Service.h"
#include "State.h"


namespace n8{
    
/**
 *  State_Manager handles the state stack and holds pointers
 *    to each registered game state.
 *
 *  The singleton pattern is used so there is a single
 *    state stack and access point to state information.
 */
class StateManagerService : public n8::Service{

public:
    StateManagerService();
    ~StateManagerService();
    
    
    bool RegisterState(EState identifier, State* state);
    
    bool PushState(EState identifier);
    void PopState();
    
    int GetStackSize();
    ID GetCurrentStateId();
    
    void ProcessState(Uint32 time, SDL_Surface* screen);
    
    
    
private:
    
    
    map<EState, State*> m_registeredStates; /** < map of identifiers and game state objects */
    stack<State*> m_stateStack; /** < stack of state objects */
    
};

}

#endif
