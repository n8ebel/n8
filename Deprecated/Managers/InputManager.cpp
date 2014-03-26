/*
 * InputManager.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            12/22/13
 * Organization:    n8Tech
 *
 */
#include <iostream>

#include "InputManager.h"
#include "State.h"



/** Default constructor
 *  Initializes event_
 */
InputManager::InputManager(){
    m_event = new SDL_Event;
}

/** Default destructor */
InputManager::~InputManager(){
    if (DEBUGGING) {
        Log::Info(INPUT_MANAGER, "Destructor was called");
    }
}

/** Responds to user queued inputs based on the current state's implementation 
 *
 *  @param currentState The currently active game state.  This state will 
 *      respond to inputs
 */
void InputManager::ProcessInputs(State* currentState){
    while(HandleEvent()){
        currentState->RespondToUserInput();
    }
}

/** Takes a polled event and tracks which events have occured
 *      so they can be responded to by a game state
 */
void InputManager::HandleInput(){
    std::cout << "Handle Input" << std::endl;
    if (SDL_PollEvent(m_event))
    {
        if (m_event->type == SDL_QUIT)
		{
			
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
bool InputManager::HandleEvent(){
    return SDL_PollEvent(m_event);
}

/** Checks whether a key is pressed down
 *  Called by the user.
 *
 *  @param key The key that is being checked
 *
 *  @return True if the key was pressed down, False otherwise
 */
bool InputManager::KeyIsDown(int key){
    return KeyIsDown(m_event, key);
}

/** Checks whether a key is up
 *  Called by the user.
 *
 *  @param key The key that is being checked
 *
 *  @return True if the key is up, False otherwise
 */
bool InputManager::KeyIsUp(int key){
    
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
bool InputManager::KeyIsDown(SDL_Event* event,int key){
    
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
bool InputManager::KeyIsUp(SDL_Event* event,int key){
    
    return false;
    
}