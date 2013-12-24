//
//  StateManager.cpp
//  goobar
//
//  Created by Nate Ebel on 12/20/13.
//  Copyright (c) 2013 n8Tech. All rights reserved.
//

#include "State_Manager.h"

State_Manager* State_Manager::instance_ = NULL;

State_Manager::~State_Manager(){
    
}

State_Manager* State_Manager::getInstance(){
    if (instance_) {
        return instance_;
    }
    else{
        instance_ = new State_Manager();
        return instance_;
    }
}

State_Manager::State_Manager(){
    
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

bool State_Manager::changeState(int identifier){
    map<int, State*>::iterator ii = registeredStates_.find(identifier);
    
    if(ii != registeredStates_.end()){
        
        currentState_ = ii->second;
        
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