//
//  StateManager.cpp
//  goobar
//
//  Created by Nate Ebel on 12/20/13.
//  Copyright (c) 2013 n8Tech. All rights reserved.
//

#include "StateManager.h"
#include <iostream>

State_Manager::~State_Manager(){
    
}
/*
State_Manager* State_Manager::getInstance(){
    
    return NULL;
}
*/

State_Manager::State_Manager(State* state1, State* state2){
    currentState = 0;
    
    states[0] = state1;
    states[1] = state2;
}