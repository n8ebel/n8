//
//  MenuState.h
//  goobar
//
//  Created by Nate Ebel on 12/22/13.
//  Copyright (c) 2013 n8Tech. All rights reserved.
//

#ifndef MENU_STATE_H
#define MENU_STATE_H

#include <iostream> 

#include "State.h"

class MenuState : public State {
public:
    MenuState();
    ~MenuState();
    
    virtual void update(Uint32 currentTime);
    virtual void render(SDL_Surface* img);
    
protected:
    
private:
    
    
};

#endif
