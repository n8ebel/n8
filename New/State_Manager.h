//
//  StateManager.h
//  goobar
//
//  Created by Nate Ebel on 12/20/13.
//  Copyright (c) 2013 n8Tech. All rights reserved.
//

#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include "State.h";


#include <map>

using namespace std;


class State_Manager{

public:
    static State_Manager* getInstance();
    virtual ~State_Manager();
    
    
    bool registerState(int identifier, State* state);
    bool changeState(int identifier);
    
    void processState(Uint32 time, SDL_Surface* screen);
    
    
private:
    State_Manager();
    
    static State_Manager* instance_;
    
    map<int, State*> registeredStates_;
    State* currentState_;
    
    
};



#endif
