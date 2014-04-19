/*
 * InputService.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            3/19/14
 * Organization:    n8Tech
 *
 */

#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <iostream>

#include "SDL2/SDL.h"
#include "Service.h"
#include "Command.h"

#include <map>



namespace n8{

class InputService :public Service {

public:
    InputService();
    
    ~InputService();
    
    void HandleInput();
    bool HandleEvent();
    bool KeyIsDown(int key);
    bool KeyIsUp(int key);
    
    void RegisterKeyUpCommand(int,Command*);
    void RegisterKeyDownCommand(int,Command*);
    
    void UnregisterKeyCommands();
    
    void OnNotify(Event* event);
private:
    
   
    
    SDL_Event* m_event; /** < SDL_Event pointer to get dequeued events */
    bool m_keysHeld[323];  /** < Array to store whether or not a key is being held down **/
    Command* m_registeredKeyDownCommands[323];
    Command* m_registeredKeyUpCommands[323];
    
    bool KeyIsDown(SDL_Event* event, int key);
    bool KeyIsUp(SDL_Event* event, int key);
    
};

}
#endif