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

#include "Singleton.h"
#include "Object.h"

class State;

class InputManager :public Singleton<InputManager>, Object {

public:
    InputManager();
    
    ~InputManager();
    
    void ProcessInputs(State*);
    void HandleInput();
    bool HandleEvent();
    bool KeyIsDown(int key);
    bool KeyIsUp(int key);
    
    
private:
    
   
    
    SDL_Event* m_event; /** < SDL_Event pointer to get dequeued events */
    bool m_keysHeld[323];  /** < Array to store whether or not a key is being held down **/
    
    bool KeyIsDown(SDL_Event* event, int key);
    bool KeyIsUp(SDL_Event* event, int key);
    
};

#endif