//
//  Event_Manager.cpp
//  goobar
//
//  Created by Nate Ebel on 1/3/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#include "Event_Manager.h"

Event_Manager* Event_Manager::instance_ = NULL;

/** Private constructor */
Event_Manager::Event_Manager(){
    
}

/** Default destructor */
Event_Manager::~Event_Manager(){
    
}

/** Singleton access method
 *
 *  @return Pointer to the Event_Manager instance
 */
Event_Manager* Event_Manager::getInstance(){
    if (instance_ == NULL) {
        instance_ = new Event_Manager();
        return instance_;
    }
    else{
        return instance_;
    }
}

/** Enqueues a new event object so it may be processed later
 *
 *  @param newEvent is a pointer to an Event object.  The event object 
 *      handles some type of system event or interaction
 *
 */
void Event_Manager::queueEvent(Event* newEvent){
    if(newEvent != NULL){
        events_.push(newEvent);
    }
}

/** Processes each queued event and then deletes the event object
 *
 */
void Event_Manager::processQueuedEvents(){
    for (int i = 0; i < events_.size(); i++) {
        Event* currentEvent = events_.front();
        currentEvent->process();
        events_.pop();
        delete currentEvent;
    }
}
