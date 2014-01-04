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

#include "Input_Manager.h"
#include "State.h"


Input_Manager* Input_Manager::instance_ = NULL;  //Static singleton instance initialzation

/** Singleton access method.
 *
 * @return Pointer to the singleton Input_Manager instance
 */
Input_Manager* Input_Manager::get_instance(){
    if(instance_){
        return instance_;
    }
    else{
        instance_ = new Input_Manager();
        return instance_;
    }
}

/** Default constructor
 *  Initializes event_
 */
Input_Manager::Input_Manager(){
    event_ = new SDL_Event;
}

/** Default destructor */
Input_Manager::~Input_Manager(){
    if (DEBUGGING) {
        Log::info(INPUT_MANAGER, "Destructor was called");
    }
}

/** Responds to user queued inputs based on the current state's implementation 
 *
 *  @param currentState The currently active game state.  This state will 
 *      respond to inputs
 */
void Input_Manager::process_inputs(State* currentState){
    while(handle_event()){
        currentState->respond_to_user_input();
    }
}

/** Takes a polled event and tracks which events have occured
 *      so they can be responded to by a game state
 */
void Input_Manager::handle_input(){
    std::cout << "Handle Input" << std::endl;
    if (SDL_PollEvent(event_))
    {
        if (event_->type == SDL_QUIT)
		{
			
		}
        
		if (event_->type == SDL_KEYDOWN)
		{
            keysHeld_[event_->key.keysym.sym] = true;
		}
		if (event_->type == SDL_KEYUP)
		{
			keysHeld_[event_->key.keysym.sym] = false;
			
		}
    }
}

/** @return True if there is an event in the queue */
bool Input_Manager::handle_event(){
    return SDL_PollEvent(event_);
}

/** checks whether a key is pressed down
 *
 *  @param key The key that is being checked
 *
 *  @return True if the key was pressed down, False otherwise
 */
bool Input_Manager::key_is_down(int key){
    return key_is_down(event_, key);
}

/** checks whether a key is up
 *
 *  @param key The key that is being checked
 *
 *  @return True if the key is up, False otherwise
 */
bool Input_Manager::key_is_up(int key){
    
    return key_is_up(event_, key);
    
}


bool Input_Manager::key_is_down(SDL_Event* event,int key){
    
    if (event->type == SDL_KEYDOWN && event->key.keysym.sym == key)
    {
        return true;
    }
		
    return false;
}

bool Input_Manager::key_is_up(SDL_Event* event,int key){
    
    return false;
    
}