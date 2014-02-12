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

#include "Singleton.h"
#include "Object.h"
#include "Event.h"

#include <queue>

using namespace std;

class EventManager :public Singleton<EventManager>,Object{

public:
    EventManager();
    ~EventManager();
    
    void QueueEvent(Event*);
    void ProcessQueuedEvents();
    
private:
    
    
    
	queue<Event*> m_events;  /** < stores events to be processed **/
};

#endif
