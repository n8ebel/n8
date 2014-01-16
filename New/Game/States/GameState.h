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
#include "EntityState.h"
#include "InputManager.h"
#include "Entity.h"


class GameState : public EntityState {
public:
    GameState();
    virtual ~GameState();
    
    virtual void OnResume();
    virtual void OnPause();
    
    
    
    virtual void RespondToUserInput();
    virtual void Update(Uint32 currentTime);
    virtual void Render(SDL_Surface* img);
    
    virtual void RegisterEntity(Entity* newEntity);
    
private:
    virtual void CreateSystems();
    virtual void CreateEntities();
    
};
#endif