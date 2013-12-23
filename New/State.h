#ifndef STATE_H
#define STATE_H

#include "SDL/SDL.h"

class State{
public:
	State();
	virtual ~State();
    
    virtual void update(Uint32 currentTime);
    virtual void render(SDL_Surface* img);

protected:
    Uint32 time;
    
private:
    

};

#endif
	