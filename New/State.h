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

#include <vector>
#include <assert.h>

#include "SDL/SDL.h"
#include "ID.h"

namespace n8{

/**
 *  Base class for game states
 *
 */
class State{
public:
    
    ID GetId() {return *m_id;};
    
    
    virtual void OnResume() = 0;
    virtual void OnPause() = 0;
    
    virtual void Update(Uint32 currentTime) = 0;
    virtual void Render(SDL_Surface* img) = 0;
    
protected:
    Uint32 m_time;  /** < holds current game time > */
    ID* m_id;  /** < unique identifier for the state oobject > */
    //vector<n8::entities::Entity*> m_stateEntities;
    
    
private:
    
};
    
}

#endif
	