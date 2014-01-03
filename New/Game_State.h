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
#include "Input_Manager.h"

class Game_State : public State {
public:
    Game_State();
    virtual ~Game_State();
    
    ID* getID() ;
    
    void start() ;
    
    void respondToUserInput();
    void update(Uint32 currentTime);
    void render(SDL_Surface* img);
    
    
    
    
    
    
    
protected:
    
private:
    
    
};
#endif