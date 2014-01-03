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


#include "State.h";
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
class State_Manager{

public:
    static State_Manager* getInstance();
    virtual ~State_Manager();
    
    
    bool registerState(int identifier, State* state);
    bool changeState(int identifier);
    void popState();
    int getStackSize();
    
    
    void processState(Uint32 time, SDL_Surface* screen);
    
    
    
private:
    State_Manager();
    
    static State_Manager* instance_;
    
    map<int, State*> registeredStates_;
    stack<State*> stateStack;
    
};



#endif
