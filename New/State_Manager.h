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
 *  State_Manager handles the state
 */
class State_Manager{

public:
    static State_Manager* getInstance();
    virtual ~State_Manager();
    
    
    bool registerState(int identifier, State* state);
    bool changeState(int identifier);
    bool popState();
    int getStackSize();
    
    void processState(Uint32 time, SDL_Surface* screen);
    
    
private:
    State_Manager();
    
    static State_Manager* instance_;
    
    map<int, State*> registeredStates_;
    stack<State*> stateStack;
    
};



#endif
