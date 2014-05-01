/*
 * InputService.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            3/19/14
 * Organization:    n8Tech
 *
 */
#include <iostream>

#include "InputService.h"
#include "Log.h"
#include "ServiceManager.h"
#include "StateManagerService.h"

#define TAG "InputService"

/** Default constructor
 *  Initializes event_
 */
n8::InputService::InputService(){
    Log::Info(TAG, "Constructor");
    //m_event = new SDL_Event;
    
    for (int i = 0; i < 323; i++) {
        m_registeredKeyDownCommands[i] = nullptr;
        m_registeredKeyUpCommands[i] = nullptr;
    }
    
    m_userInterface = nullptr;
    
    m_mouseMoveCommand = nullptr;
    m_mouseButtonDownCommand = nullptr;
    m_mouseButtonUpCommand = nullptr;
    
    m_mouseMoveFunction = nullptr;
    m_mouseButtonDownFunction = nullptr;
    m_mouseButtonUpFunction = nullptr;
}

/** Default destructor */
n8::InputService::~InputService(){
    Log::Info(TAG, "Destructor");
}


/** Takes a polled event and tracks which events have occured
 *      so they can be responded to by a game state
 */
void n8::InputService::HandleInput(){
    if (SDL_PollEvent(&m_event))
    {
        bool guiHasFocus = false;
        if(m_userInterface){
            m_userInterface->ProcessInput(&m_event);
            guiHasFocus = m_userInterface->HasFocus();
        }
        
        
        if (m_event.type == SDL_QUIT)
		{
            Event event(EEvents::Values::Exit);
            Notify(&event);
		}
        
        if (!guiHasFocus) {
            if (m_event.type == SDL_KEYDOWN)
            {
                m_keysHeld[m_event.key.keysym.sym] = true;
                if(m_registeredKeyDownCommands[m_event.key.keysym.sym] != nullptr){
                    m_registeredKeyDownCommands[m_event.key.keysym.sym]->execute();
                }
            }
            if (m_event.type == SDL_KEYUP)
            {
                m_keysHeld[m_event.key.keysym.sym] = false;
                if (m_registeredKeyUpCommands[m_event.key.keysym.sym] != nullptr) {
                    m_registeredKeyUpCommands[m_event.key.keysym.sym]->execute();
                }
            }

        }
        
        if( m_event.type == SDL_MOUSEMOTION  )
        {
            if(m_mouseMoveCommand){
               m_mouseMoveCommand->execute();
            }
            if (m_mouseMoveFunction) {
                m_mouseMoveFunction();
            }
        }
        if( m_event.type == SDL_MOUSEBUTTONDOWN){
            int x,y;
            SDL_GetMouseState(&x, &y);
            
            if(m_mouseButtonDownCommand){
                m_mouseButtonDownCommand->execute(x,y);
            }
            if (m_mouseButtonDownFunction) {
                m_mouseButtonDownFunction(x,y);
            }
        }
        if( m_event.type == SDL_MOUSEBUTTONUP){
            int x,y;
            SDL_GetMouseState(&x, &y);
            
            if(m_mouseButtonUpCommand){
                m_mouseButtonUpCommand->execute(x,y);
            }
            if (m_mouseButtonUpFunction) {
                m_mouseButtonUpFunction(x,y);
            }
        }
    }
}

/** @return True if there is an event in the queue */
bool n8::InputService::HandleEvent(){
    return SDL_PollEvent(&m_event);
}

/** Checks whether a key is pressed down
 *  Called by the user.
 *
 *  @param key The key that is being checked
 *
 *  @return True if the key was pressed down, False otherwise
 */
bool n8::InputService::KeyIsDown(int key){
    return KeyIsDown(&m_event, key);
}

/** Checks whether a key is up
 *  Called by the user.
 *
 *  @param key The key that is being checked
 *
 *  @return True if the key is up, False otherwise
 */
bool n8::InputService::KeyIsUp(int key){
    
    return KeyIsUp(&m_event, key);
    
}

void n8::InputService::RegisterUserInterface(gui::GUI* p_gui){
    m_userInterface = p_gui;
}

void n8::InputService::RegisterKeyDownCommand(int key,Command* command){
    m_registeredKeyDownCommands[key] = command;
}

void n8::InputService::RegisterKeyUpCommand(int key,Command* command){
    m_registeredKeyUpCommands[key] = command;
}

void n8::InputService::UnregisterKeyCommands(){
    for (int i = 0; i < 323; i++) {
        m_registeredKeyUpCommands[i] = nullptr;
        m_registeredKeyDownCommands[i] = nullptr;
    }
}

/** Checks whether a key is pressed down
 *  Called internally by KeyIsDown(int key).
 *
 *  @param event The event object storing event information
 *  @param key The key that is being checked
 *
 *  @return True if the specified key was pressed down, False otherwise
 */
bool n8::InputService::KeyIsDown(SDL_Event* event,int key){
    
    if (event->type == SDL_KEYDOWN && event->key.keysym.sym == key)
    {
        return true;
    }
		
    return false;
}

/** Checks whether a key is up
 *  Called internally by KeyIsUp(int key).
 *
 *  @param event The event object storing event information
 *  @param key The key that is being checked
 *
 *  @return True if the specified key is up, False otherwise
 */
bool n8::InputService::KeyIsUp(SDL_Event* event,int key){
    
    return false;
    
}

void n8::InputService::RegisterMouseMoveAction(Command* p_command){
    m_mouseMoveCommand = p_command;
}

void n8::InputService::RegisterMouseMoveAction(std::function<void()> func){
    m_mouseMoveFunction = func;
}

void n8::InputService::UnregisterMouseMoveAction(){
    m_mouseMoveCommand = nullptr;
    m_mouseMoveFunction = nullptr;
}

void n8::InputService::RegisterMouseButtonDownAction(PositionCommand* p_command){
    m_mouseButtonDownCommand = p_command;
}

void n8::InputService::RegisterMouseButtonDownAction(std::function<void(int,int)> func){
    m_mouseButtonDownFunction = func;
}

void n8::InputService::UnregisterMouseButtonDownAction(){
    m_mouseButtonDownCommand = nullptr;
    m_mouseButtonDownFunction = nullptr;
}

void n8::InputService::RegisterMouseButtonUpAction(PositionCommand* p_command){
    m_mouseButtonUpCommand = p_command;
}

void n8::InputService::RegisterMouseButtonUpAction(std::function<void(int,int)> func){
    m_mouseButtonUpFunction = func;
}

void n8::InputService::UnregisterMouseButtonUpAction(){
    m_mouseButtonUpCommand = nullptr;
    m_mouseButtonUpFunction = nullptr;
}

void n8::InputService::OnNotify(Event* event){
    
}