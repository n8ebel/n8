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
    virtual ~State_Manager();
    State_Manager();
    
    bool registerState(int identifier, State* state);
    
    void processState(Uint32 time, SDL_Surface* screen);
    
    
private:
    map<int, State*> registeredStates_;
    State* currentState_;
    
};



#endif
