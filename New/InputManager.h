//
//  InputManager.h
//  goobar
//
//  Created by Nate Ebel on 12/23/13.
//  Copyright (c) 2013 n8Tech. All rights reserved.
//

#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <iostream>

#include "SDL/SDL.h"

class InputManager{

public:
    
    static InputManager* getInstance();
    ~InputManager();
    
    void handle_input();
    bool key_is_down(int key);
    bool key_is_up(int key);
    
private:
    
    static InputManager* instance_;
    InputManager();
    
    bool keysHeld_[323];  /** < Array to store whether or not a key is being held down **/
    
    
  	
    SDL_Event event_;
    
};

#endif