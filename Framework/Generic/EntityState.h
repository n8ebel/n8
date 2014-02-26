/*
 * EntityState.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            12/22/13
 * Organization:    n8Tech
 *
 */

#ifndef ENTITY_STATE_H
#define ENTITY_STATE_H

#include "Entity.h"
#include "State.h"

#include <vector>

/**
 *  Base class for game states
 *
 */
class EntityState : public State{
public:
    
    virtual void OnResume() = 0;
    virtual void OnPause() = 0;
    
    virtual void Update(Uint32 currentTime) = 0;
    virtual void Render(SDL_Surface* img) = 0;
    
    virtual void RespondToUserInput() = 0;
    
    
    virtual void RegisterEntity(Entity* newEntity) = 0;
    

protected:
    
    vector<Entity*> m_entities;  /** < Stores list of state entities */
    
private:
    virtual void CreateSystems() {Log::Info("State", "Create Systems");};
    virtual void CreateEntities() {};
    
};

#endif
	