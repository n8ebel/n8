//
//  Event_Manager.cpp
//  goobar
//
//  Created by Nate Ebel on 1/3/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#include "EventManager.h"



/** Private constructor */
EventManager::EventManager(){
    
}

/** Default destructor */
EventManager::~EventManager(){
    if(DEBUGGING){
        Log::Info(EVENT_MANAGER, "Destructor was called");
    }
}



/** Enqueues a new event object so it may be processed later
 *
 *  @param newEvent is a pointer to an Event object.  The event object 
 *      handles some type of system event or interaction
 *
 */
void EventManager::QueueEvent(Event* newEvent){
    if(newEvent != NULL){
        m_events.push(newEvent);
    }
}

/** Processes each queued event and then deletes the event object
 *
 */
void EventManager::ProcessQueuedEvents(){
    for (int i = 0; i < m_events.size(); i++) {
        Event* currentEvent = m_events.front();
        currentEvent->Process();
        m_events.pop();
        delete currentEvent;
    }
}
