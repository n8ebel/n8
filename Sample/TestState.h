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
#include <vector>

#include "State.h"
#include "Event.h"
#include "RenderService.h"
#include "AudioService.h"

#include "InputService.h"
#include "StateManagerService.h"
#include "ResourceManager.h"
#include "ServiceManager.h"
#include "PopStateCommand.h"
#include "PushStateCommand.h"


#include "Sprite.h"

#include "GUI.h"
#include "Button.h"
#include "Container.h"
#include "InputBox.h"
#include "Label.h"

class Entity;

class TestState : public n8::State {
public:
    TestState();
    virtual ~TestState();
    
    virtual void OnResume();
    virtual void OnPause();
    
    virtual void Update(Uint32 currentTime);
    virtual void Render(n8::Window* window);
    
    virtual void RegisterEntity(Entity* newEntity);
    
private:
    virtual void CreateSystems();
    virtual void CreateEntities();
    
    n8::InputService* m_inputService;
    n8::RenderService* m_renderService;
    n8::AudioService* m_audioService;
    
    n8::Event m_exitEvent;
    
    n8::Font* m_font;
    gui::GUI* m_gui;
    gui::Button* m_button1;
    gui::Button* m_button2;
    gui::Container* m_toolbar;
    gui::InputBox* m_inputBox;
    gui::Label* m_label;
    
    n8::PushStateCommand m_pushStateCommand;
    n8::PopStateCommand m_popStateCommand;
    
};
#endif