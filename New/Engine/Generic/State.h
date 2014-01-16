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
    
    ID* GetId() {assert(m_id); return m_id;};
    
    
    virtual void OnResume() = 0;
    virtual void OnPause() = 0;
    
    virtual void Update(Uint32 currentTime) = 0;
    virtual void Render(SDL_Surface* img) = 0;
    
    virtual void RespondToUserInput() = 0;
    

protected:
    Uint32 m_time;
    ID* m_id;
    
    
    
private:
    virtual void CreateSystems() {Log::Info("State", "Create Systems");};
    
};

#endif
	