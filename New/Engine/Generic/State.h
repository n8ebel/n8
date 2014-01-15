/*
 * State.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            12/22/13
 * Organization:    n8Tech
 *
 */

#ifndef STATE_H
#define STATE_H

#include "Object.h"
#include "ID.h"
#include "Entity.h"

#include <vector>

/**
 *  Base class for game states
 *
 */
class State{
public:
    //virtual ~State() = 0;
    
    virtual ID* GetId() = 0;
    
    
    virtual void OnResume() = 0;
    virtual void OnPause() = 0;
    
    
    virtual void RespondToUserInput() = 0;
    virtual void Update(Uint32 currentTime) = 0;
    virtual void Render(SDL_Surface* img) = 0;
    
    virtual void RegisterEntity(Entity* newEntity) = 0;
    

protected:
    Uint32 m_time;
    ID* m_id;
    
    vector<Entity*> m_entities;  /** < Stores list of state entities */
    
private:
    
};

#endif
	