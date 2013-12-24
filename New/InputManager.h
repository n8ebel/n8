/*
 * InputManager.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            12/22/13
 * Organization:    n8Tech
 *
 */

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
    
    SDL_Event *event_;
    
private:
    
    static InputManager* instance_;
    InputManager();
    
    bool keysHeld_[323];  /** < Array to store whether or not a key is being held down **/
    
    
  	
    
    
};

#endif