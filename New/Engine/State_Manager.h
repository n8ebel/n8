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
#include "Event_Manager.h"

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
class State_Manager :public Object{

public:
    static State_Manager* get_instance();
    virtual ~State_Manager();
    
    
    bool register_state(int identifier, State* state);
    
    bool push_state(int identifier);
    void pop_state();
    
    int get_stack_size();
    ID* get_current_state_id();
    
    void process_state(Uint32 time, SDL_Surface* screen);
    
    
    
private:
    State_Manager();
    
    static State_Manager* instance_; /** < static singleton instance */
    
    map<int, State*> registeredStates_; /** < map of identifiers and game state objects */
    stack<State*> stateStack; /** < stack of state objects */
    
};



#endif
