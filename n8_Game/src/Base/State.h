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

#include <iostream>
#include <vector>
#include <assert.h>

#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"

#include "ID.h"
#include "Window.h"
#include "GUI.h"

class SDL_Window;

namespace n8{

    class Game;
    
/** \class State
 *  \brief Abstract base class for game states
 *
 */
class State{
public:
    
    State(n8::Game* game);
    ~State();
    
    ID GetId();
    
    
    virtual void OnResume() = 0;
    virtual void OnPause() = 0;
    
    virtual void Update(Uint32 currentTime);
    virtual void Render(Window* window);
    
    gui::GUI* GetGUI();
    
protected:
    Uint32 m_time;  /** < holds current game time > */
    ID* m_id;  /** < unique identifier for the state oobject > */
    //vector<n8::entities::Entity*> m_stateEntities;
    
    n8::Game* m_game;
    
private:
    gui::GUI* m_gui;
    
};
    
}

#endif
	