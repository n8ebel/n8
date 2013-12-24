/*
 * State_Manager.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            12/22/13
 * Organization:    n8Tech
 *
 */

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
            
            stateStack.push(state);
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
        
        stateStack.push( ii->second);
        
        return true;
    }
    else{
        
        return false;
    }

}

bool State_Manager::popState(){
    if (stateStack.size() == 0) {
        return false;
    }
    else{
        stateStack.pop();
        return true;
    }
}

int State_Manager::getStackSize(){
    return stateStack.size();
}

void State_Manager::processState(Uint32 time, SDL_Surface* screen){
    
    stateStack.top()->processInput();
    stateStack.top()->update(time);
    stateStack.top()->render(screen);
}