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

#include "Values.h"
#include "State.h"
#include "InputManager.h"
#include "Entity.h"


class GameState : public State {
public:
    GameState();
    virtual ~GameState();
    
    ID* GetId() ;
    
   
    void OnResume();
    void OnPause();
    
    
    
    void RespondToUserInput();
    void Update(Uint32 currentTime);
    void Render(SDL_Surface* img);
    
    void RegisterEntity(Entity* newEntity);
    
private:
    
    
};
#endif