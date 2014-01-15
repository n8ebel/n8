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
    
    ID* GetId() ;
    
    
    void OnResume();
    void OnPause();
    
    
    
    void RespondToUserInput();
    void Update(Uint32 currentTime);
    void Render(SDL_Surface* img);
    
    void RegisterEntity(Entity* newEntity);
    
    
protected:
    
private:
    
    
};

#endif
