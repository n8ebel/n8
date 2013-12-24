//
//  GameState.h
//  goobar
//
//  Created by Nate Ebel on 12/23/13.
//  Copyright (c) 2013 n8Tech. All rights reserved.
//

#ifndef __goobar__GameState__
#define __goobar__GameState__

#include <iostream>

#include "State.h"
#include "InputManager.h"

class GameState : public State {
public:
    GameState();
    ~GameState();
    
    ID* getID() ;
    
    void start() ;
    
    void processInput();
    void update(Uint32 currentTime);
    void render(SDL_Surface* img);
    
    
    
    
    
    
    
protected:
    
private:
    
    
};
#endif