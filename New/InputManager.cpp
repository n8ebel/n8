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
#include "InputManager.h"

InputManager* InputManager::instance_ = NULL;

InputManager* InputManager::getInstance(){
    if(instance_){
        return instance_;
    }
    else{
        instance_ = new InputManager();
        return instance_;
    }
}

InputManager::InputManager(){
    event_ = new SDL_Event;
}

void InputManager::handle_input(){
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

bool InputManager::key_is_down(int key){
    if (SDL_PollEvent(event_))
    {
        if (event_->type == SDL_KEYDOWN && event_->key.keysym.sym == key)
		{
			return true;
		}
		
        
    }
    
    return false;
}

bool InputManager::key_is_up(int key){
    
    return false;
    
}