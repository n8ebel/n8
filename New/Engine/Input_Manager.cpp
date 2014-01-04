/*
 * InputManager.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            12/22/13
 * Organization:    n8Tech
 *
 */
#include <iostream>

#include "Input_Manager.h"
#include "State.h"


Input_Manager* Input_Manager::instance_ = NULL;  //Static singleton instance initialzation

Input_Manager* Input_Manager::getInstance(){
    if(instance_){
        return instance_;
    }
    else{
        instance_ = new Input_Manager();
        return instance_;
    }
}

Input_Manager::Input_Manager(){
    event_ = new SDL_Event;
}

Input_Manager::~Input_Manager(){
    if (DEBUGGING) {
        Log::info(INPUT_MANAGER, "Destructor was called");
    }
}

void Input_Manager::process_inputs(State* currentState){
    while(handle_event()){
        currentState->respondToUserInput();
    }
}

void Input_Manager::handle_input(){
    std::cout << "Handle Input" << std::endl;
    if (SDL_PollEvent(event_))
    {
        if (event_->type == SDL_QUIT)
		{
			
		}
        
		if (event_->type == SDL_KEYDOWN)
		{
            std::cout << event_->key.keysym.sym << std::endl;
			keysHeld_[event_->key.keysym.sym] = true;
		}
		if (event_->type == SDL_KEYUP)
		{
			keysHeld_[event_->key.keysym.sym] = false;
			
		}
    }
}

bool Input_Manager::handle_event(){
    return SDL_PollEvent(event_);
}

bool Input_Manager::key_is_down(int key){
    return key_is_down(event_, key);
}

bool Input_Manager::key_is_up(int key){
    
    return key_is_up(event_, key);
    
}

bool Input_Manager::key_is_down(SDL_Event* event,int key){
    
        if (event->type == SDL_KEYDOWN && event->key.keysym.sym == key)
		{
			return true;
		}
		
        
    
    
    return false;
}

bool Input_Manager::key_is_up(SDL_Event* event,int key){
    
    return false;
    
}