//
//  StateManager.h
//  goobar
//
//  Created by Nate Ebel on 12/20/13.
//  Copyright (c) 2013 n8Tech. All rights reserved.
//

#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include "State.h":

class State_Manager{

public:
    virtual ~State_Manager();
    State_Manager(State* state1, State* state2);
    
    int currentState;
    
    State* states[2];
    
    //State_Manager* getInstance();
    
private:
   
    
};



#endif
