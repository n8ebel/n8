//
//  StateManager.cpp
//  goobar
//
//  Created by Nate Ebel on 12/20/13.
//  Copyright (c) 2013 n8Tech. All rights reserved.
//

#include "StateManager.h"

State_Manager::~State_Manager(){
    
}


State_Manager::State_Manager(){
    currentState_ = NULL;
}

bool State_Manager::registerState(int identifier, State* state){
    map<int, State*>::iterator ii = registeredStates_.find(identifier);
    
    if(ii == registeredStates_.end()){
        registeredStates_[identifier] = state;
        
        if(registeredStates_.size() == 1){
            
            currentState_ = state;
        }
        return true;
    }
    else{
        
        
        return false;
    }
    
    
    
}

void State_Manager::processState(Uint32 time, SDL_Surface* screen){
    
    currentState_->processInput();
    currentState_->update(time);
    currentState_->render(screen);
}