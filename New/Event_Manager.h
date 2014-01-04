/*
 * Event_Manager.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            1/3/14
 * Organization:    n8Tech
 *
 */

#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

//#include "n8.h"
#include "Event.h"

#include <queue>

class Event;

using namespace std;

class Event_Manager {

public:
    static Event_Manager* getInstance();
    
    ~Event_Manager();
    
    void queueEvent(Event*);
    void processQueuedEvents();
    
private:
    static Event_Manager* instance_;
    Event_Manager();
    
	queue<Event*> events_;
};

#endif
