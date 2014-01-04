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

#include "Object.h"
#include "Event.h"

#include <queue>

using namespace std;

class Event_Manager :public Object{

public:
    static Event_Manager* get_instance();
    
    ~Event_Manager();
    
    void queue_event(Event*);
    void process_queued_events();
    
private:
    static Event_Manager* instance_;
    Event_Manager();
    
	queue<Event*> events_;  /** < stores events to be processed **/
};

#endif
