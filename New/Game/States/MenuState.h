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

#include "Values.h"
#include "State.h"
#include "InputManager.h"


class MenuState : public State {
public:
    MenuState();
    ~MenuState();
    
    virtual void OnResume();
    virtual void OnPause();
    
    
    
    virtual void RespondToUserInput();
    virtual void Update(Uint32 currentTime);
    virtual void Render(SDL_Surface* img);
    
    
protected:
    
private:
    virtual void CreateSystems();
    
    
};

#endif
