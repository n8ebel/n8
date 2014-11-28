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
    
    State(std::shared_ptr<n8::Game> game);
    ~State();
    
    const ID& GetId() const;
    
    
    virtual void OnResume() = 0;
    virtual void OnPause() = 0;
    
    virtual void Update(Uint32 currentTime);
    virtual void Render(Window* window);
    
    const std::shared_ptr<gui::GUI> GetGUI() const;
    
protected:
    Uint32 m_time;  /** < holds current game time > */
    std::unique_ptr<ID> m_id;  /** < unique identifier for the state oobject > */
    
    std::shared_ptr<n8::Game> m_game;
    
private:
    std::shared_ptr<gui::GUI> m_gui;
    
};
    
}

#endif
	