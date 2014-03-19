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
            static_cast<StateManagerService*>(ServiceManager::GetInstance()->GetService(EService::StateManager))->PopState();
		}
        
		if (m_event->type == SDL_KEYDOWN)
		{
            m_keysHeld[m_event->key.keysym.sym] = true;
		}
		if (m_event->type == SDL_KEYUP)
		{
			m_keysHeld[m_event->key.keysym.sym] = false;
			
		}
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