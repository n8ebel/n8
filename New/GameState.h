/*
 * GameState.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            12/22/13
 * Organization:    n8Tech
 *
 */

#ifndef __goobar__GameState__
#define __goobar__GameState__

#include <iostream>

#include "State.h"
#include "InputManager.h"

class GameState : public State {
public:
    GameState();
    virtual ~GameState();
    
    ID* getID() ;
    
    void start() ;
    
    void processInput();
    void update(Uint32 currentTime);
    void render(SDL_Surface* img);
    
    
    
    
    
    
    
protected:
    
private:
    
    
};
#endif