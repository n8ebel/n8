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
    m_event = new SDL_Event;
    
    for (int i = 0; i < 323; i++) {
        m_registeredKeyDownCommands[i] = NULL;
        m_registeredKeyUpCommands[i] = NULL;
    }
    
    m_mouseMoveCommand=NULL;
}

/** Default destructor */
n8::InputService::~InputService(){
    Log::Info(TAG, "Destructor");
}


/** Takes a polled event and tracks which events have occured
 *      so they can be responded to by a game state
 */
void n8::InputService::HandleInput(){
    if (SDL_PollEvent(m_event))
    {
        if (m_event->type == SDL_QUIT)
		{
            Event event(EEvents::Values::Exit);
            Notify(&event);
		}
        
		if (m_event->type == SDL_KEYDOWN)
		{
            
            m_keysHeld[m_event->key.keysym.sym] = true;
            /*
            if (m_event->key.keysym.sym == SDLK_SPACE) {
                std::cout << "pressed space" << std::endl;
                Event event(EEvents::Values::Test2);
                Notify(&event);
            }
             */
            if(m_registeredKeyDownCommands[m_event->key.keysym.sym] != NULL){
                m_registeredKeyDownCommands[m_event->key.keysym.sym]->execute();
            }
		}
		if (m_event->type == SDL_KEYUP)
		{
			m_keysHeld[m_event->key.keysym.sym] = false;
            if (m_registeredKeyUpCommands[m_event->key.keysym.sym] != NULL) {
                m_registeredKeyUpCommands[m_event->key.keysym.sym]->execute();
            }
            
			
		}
        if( m_event->type == SDL_MOUSEMOTION  )
        {
            if(m_mouseMoveCommand){
                m_mouseMoveCommand->execute();
            }
        
        }
        if( m_event->type == SDL_MOUSEBUTTONDOWN){
            if(m_mouseButtonDownCommand){
                m_mouseButtonDownCommand->execute();
            }
        }
        //|| m_event->type == SDL_MOUSEBUTTONUP
    }
}

/** @return True if there is an event in the queue */
bool n8::InputService::HandleEvent(){
    return SDL_PollEvent(m_event);
}

/** Checks whether a key is pressed down
 *  Called by the user.
 *
 *  @param key The key that is being checked
 *
 *  @return True if the key was pressed down, False otherwise
 */
bool n8::InputService::KeyIsDown(int key){
    return KeyIsDown(m_event, key);
}

/** Checks whether a key is up
 *  Called by the user.
 *
 *  @param key The key that is being checked
 *
 *  @return True if the key is up, False otherwise
 */
bool n8::InputService::KeyIsUp(int key){
    
    return KeyIsUp(m_event, key);
    
}

void n8::InputService::RegisterKeyDownCommand(int key,Command* command){
    m_registeredKeyDownCommands[key] = command;
}

void n8::InputService::RegisterKeyUpCommand(int key,Command* command){
    m_registeredKeyUpCommands[key] = command;
}

void n8::InputService::UnregisterKeyCommands(){
    for (int i = 0; i < 323; i++) {
        m_registeredKeyUpCommands[i] = NULL;
        m_registeredKeyDownCommands[i] = NULL;
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

void n8::InputService::RegisterMouseMoveCommand(Command* p_command){
    m_mouseMoveCommand = p_command;
}

void n8::InputService::UnregisterMouseMoveCommand(){
    m_mouseMoveCommand = NULL;
}

void n8::InputService::RegisterMouseButtonDownCommand(Command* p_command){
    m_mouseButtonDownCommand = p_command;
}

void n8::InputService::UnregisterMouseButtonDownCommand(){
    m_mouseButtonDownCommand = NULL;
}

void n8::InputService::OnNotify(Event* event){
    
}