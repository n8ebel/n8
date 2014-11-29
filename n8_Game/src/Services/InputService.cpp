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
n8::InputService::InputService(std::shared_ptr<n8::Game> game) : Service(game){
    Log::Info(TAG, "Constructor");
    //m_event = new SDL_Event;
    
    for (int i = 0; i < 323; i++) {
        m_registeredKeyDownActions[i] = nullptr;
        m_registeredKeyUpActions[i] = nullptr;
    }
    
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
    while (SDL_PollEvent(&m_event))
    {
        bool guiHasFocus = false;
        if(m_userInterface){
            m_userInterface->ProcessInput(&m_event);
            guiHasFocus = m_userInterface->HasFocus();
        }
        
        if (m_event.type == SDL_QUIT || m_event.type == SDL_WINDOWEVENT_CLOSE)
		{
            Notify(make_shared<Event>(ExitEvent));
		}
        
        if (!guiHasFocus) {
            if (m_event.type == SDL_KEYDOWN)
            {
                m_keysHeld[m_event.key.keysym.sym] = true;
                
                if(m_registeredKeyDownActions[m_event.key.keysym.sym] != nullptr){
                    m_registeredKeyDownActions[m_event.key.keysym.sym]();
                }
            }
            if (m_event.type == SDL_KEYUP)
            {
                m_keysHeld[m_event.key.keysym.sym] = false;
                
                if (m_registeredKeyUpActions[m_event.key.keysym.sym] != nullptr) {
                    m_registeredKeyUpActions[m_event.key.keysym.sym]();
                }
            }

        }
        
        if( m_event.type == SDL_MOUSEMOTION  )
        {
            int x,y;
            SDL_GetMouseState(&x, &y);
            
            if (m_mouseMoveFunction) {
                m_mouseMoveFunction(x,y);
            }
        }
        if( m_event.type == SDL_MOUSEBUTTONDOWN){
            int x,y;
            SDL_GetMouseState(&x, &y);
            
            if (m_mouseButtonDownFunction) {
                m_mouseButtonDownFunction(x,y);
            }
        }
        if( m_event.type == SDL_MOUSEBUTTONUP){
            int x,y;
            SDL_GetMouseState(&x, &y);
            
            if (m_mouseButtonUpFunction) {
                m_mouseButtonUpFunction(x,y);
            }
        }
    }
}

/**  Gets the next event from the SDL event queue
 *
 *  @return True if there is an event in the queue 
 */
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

/** Stores a pointer to a user interface so inputs can be routed to the interface
 *  and handled.
 *
 *  @param p_gui Pointer to a user interface
 */
void n8::InputService::RegisterUserInterface(const std::shared_ptr<gui::GUI> p_gui){
    m_userInterface = p_gui;
}

void n8::InputService::RegisterKeyDownAction(int key, std::function<void()> func){
    m_registeredKeyDownActions[key] = func;
}

void n8::InputService::RegisterKeyUpAction(int key, std::function<void()> func){
    m_registeredKeyUpActions[key] = func;
}

void n8::InputService::UnregisterKeyActions(){
    for (int i = 0; i < 323; i++) {
        m_registeredKeyUpActions[i] = nullptr;
        m_registeredKeyDownActions[i] = nullptr;
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

/** Stores a functor to run when the mouse is moved
 *
 *  @param func The functor to run when the mouse is moved
 */
void n8::InputService::RegisterMouseMoveAction(std::function<void(int, int)> func){
    m_mouseMoveFunction = func;
}

/** Removes any registered command or functor that was registered to be executed when the mouse is moved.
 */
void n8::InputService::UnregisterMouseMoveAction(){
    m_mouseMoveFunction = nullptr;
}

/** Stores a functor to run when the left mouse button is clicked
 *
 *  @param func Functor to run when the left mouse button is clicked.
 */
void n8::InputService::RegisterMouseButtonDownAction(std::function<void(int,int)> func){
    m_mouseButtonDownFunction = func;
}

/** Removes any registered command or functor that was registered to be executed when the left mouse button is clicked.
 */
void n8::InputService::UnregisterMouseButtonDownAction(){
    m_mouseButtonDownFunction = nullptr;
}

/** Stores a functor to run when the left mouse button is released up
 *
 *  @param func Functor to run when the left mouse button is released up.
 */
void n8::InputService::RegisterMouseButtonUpAction(std::function<void(int,int)> func){
    m_mouseButtonUpFunction = func;
}

/** Removes any registered command or functor that was registered to be executed when the left mouse button is released up.
 */
void n8::InputService::UnregisterMouseButtonUpAction(){
    m_mouseButtonUpFunction = nullptr;
}

/** Responds to notifications from registered subjects
 *
 *  @param event The event that was broadcast by a registered subject
 */
void n8::InputService::OnNotify(std::shared_ptr<Event> event){
    
}