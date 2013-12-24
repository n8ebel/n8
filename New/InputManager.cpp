//
//  InputManager.cpp
//  goobar
//
//  Created by Nate Ebel on 12/23/13.
//  Copyright (c) 2013 n8Tech. All rights reserved.
//

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
    
}

void InputManager::handle_input(){
    if (SDL_PollEvent(&event_))
    {
        if (event_.type == SDL_QUIT)
		{
			
		}
        
		if (event_.type == SDL_KEYDOWN)
		{
			keysHeld_[event_.key.keysym.sym] = true;
		}
		if (event_.type == SDL_KEYUP)
		{
			keysHeld_[event_.key.keysym.sym] = false;
			
		}
    }
}

bool InputManager::key_is_down(int key){
    if (SDL_PollEvent(&event_))
    {
        if (event_.type == SDL_KEYDOWN && event_.key.keysym.sym == key)
		{
			return true;
		}
		
        
    }
    
    return false;
}

bool InputManager::key_is_up(int key){
    
    return false;
    
}