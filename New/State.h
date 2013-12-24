#ifndef STATE_H
#define STATE_H

#include "SDL/SDL.h"

#include "Object.h"
#include "ID.h"


class State{
public:
    
    
    virtual ID* getID() = 0;
    
    virtual void start() = 0;
    
    virtual void processInput() = 0;
    virtual void update(Uint32 currentTime) = 0;
    virtual void render(SDL_Surface* img) = 0;
    
    

protected:
    Uint32 time_;
    ID* id_;
    
private:
    
};

#endif
	