//
//  GameManager.h
//  goobar
//
//  Created by Nate Ebel on 12/22/13.
//  Copyright (c) 2013 n8Tech. All rights reserved.
//

#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "StateManager.h"

class GameManager{

public:
    GameManager();
    ~GameManager();
    
    int fps;
    Uint32 currentTime;
    
    State_Manager* stateManager;
    
    void start();
    
protected:
    
private:
    
    SDL_Surface* background;
    
    
};



#endif
