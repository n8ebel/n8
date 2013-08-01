/*
 * cScreen.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

#ifndef n8_cScreen_h
#define n8_cScreen_h

#include "SDL/SDL.h"

class cScreen{
    
private:
    SDL_Surface* screen;
    
public:
    
    ~cScreen();
    cScreen();
    
};

#endif
