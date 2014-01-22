/*
 * State_Manager.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            12/22/13
 * Organization:    n8Tech
 *
 */

#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H


#include "State.h"
#include "EventManager.h"
#include "Singleton.h"
#include "Object.h"

#include <map>
#include <stack>

using namespace std;



/**
 *  State_Manager handles the state stack and holds pointers
 *    to each registered game state.
 *
 *  The singleton pattern is used so there is a single
 *    state stack and access point to state information.
 */
class StateManager :public Singleton<StateManager>, Object{

public:
    virtual ~StateManager();
    
    
    bool RegisterState(int identifier, State* state);
    
    bool PushState(int identifier);
    void PopState();
    
    int GetStackSize();
    ID GetCurrentStateId();
    
    void ProcessState(Uint32 time, SDL_Surface* screen);
    
    
    
private:
    
    
    map<int, State*> m_registeredStates; /** < map of identifiers and game state objects */
    stack<State*> m_stateStack; /** < stack of state objects */
    
};



#endif
