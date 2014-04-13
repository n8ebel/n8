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

#include "State.h"
#include "Event.h"
#include "InputService.h"
#include "StateManagerService.h"
#include "ServiceManager.h"
#include "PopStateCommand.h"

class Entity;

class TestState : public n8::State {
public:
    TestState();
    virtual ~TestState();
    
    virtual void OnResume();
    virtual void OnPause();
    
    virtual void Update(Uint32 currentTime);
    virtual void Render(SDL_Window* window);
    
    virtual void RegisterEntity(Entity* newEntity);
    
private:
    virtual void CreateSystems();
    virtual void CreateEntities();
    
    n8::InputService* m_inputService;
    n8::Event m_exitEvent;
    
};
#endif