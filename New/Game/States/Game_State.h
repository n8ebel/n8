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
#include "State.h"
#include "Input_Manager.h"


class Game_State : public State {
public:
    Game_State();
    virtual ~Game_State();
    
    ID* get_id() ;
    
   
    void on_resume();
    void on_pause();
    
    
    
    void respond_to_user_input();
    void update(Uint32 currentTime);
    void render(SDL_Surface* img);
    
    
private:
    
    
};
#endif