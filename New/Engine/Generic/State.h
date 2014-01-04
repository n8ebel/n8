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

/**
 *  Base class for game states
 *
 */
class State{
public:
    //virtual ~State() = 0;
    
    virtual ID* get_id() = 0;
    
    
    virtual void on_resume() = 0;
    virtual void on_pause() = 0;
    
    
    virtual void respond_to_user_input() = 0;
    virtual void update(Uint32 currentTime) = 0;
    virtual void render(SDL_Surface* img) = 0;
    
    

protected:
    Uint32 time_;
    ID* id_;
    
private:
    
};

#endif
	