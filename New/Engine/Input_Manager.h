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

#include "Object.h"

class State;

class Input_Manager :public Object {

public:
    
    static Input_Manager* get_instance();
    ~Input_Manager();
    
    void process_inputs(State*);
    void handle_input();
    bool handle_event();
    bool key_is_down(int key);
    bool key_is_up(int key);
    
    
private:
    
    static Input_Manager* instance_;
    Input_Manager();
    
    SDL_Event *event_; /** < SDL_Event pointer to get dequeued events */
    
    bool keysHeld_[323];  /** < Array to store whether or not a key is being held down **/
    
    bool key_is_down(SDL_Event* event, int key);
    bool key_is_up(SDL_Event* event, int key);
    
  	
    
    
};

#endif