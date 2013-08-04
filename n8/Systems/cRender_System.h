/*
 * cRender_System.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/30/13
 * Organization:    n8Tech
 *
 */

#ifndef n8_cRender_System_h
#define n8_cRender_System_h

#include "cSystem.h"
#include "SDL/SDL.h"

class cRender_System : public cSystem {

private:
    
public:
    ~cRender_System();
    cRender_System();
    
    void update();
    void render();
    
    void draw_image( int x, int y, SDL_Surface* source, SDL_Surface* destination );
    
};


#endif
