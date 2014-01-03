/*
 * MenuState.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            12/22/13
 * Organization:    n8Tech
 *
 */

#ifndef MENU_STATE_H
#define MENU_STATE_H

#include <iostream> 

#include "State.h"
#include "Input_Manager.h"


class Menu_State : public State {
public:
    Menu_State();
    ~Menu_State();
    
    ID* getID() ;
    
    void start() ;
    
    void respondToUserInput();
    void update(Uint32 currentTime);
    void render(SDL_Surface* img);
    
    
    
    
    
    
    
protected:
    
private:
    
    
};

#endif
