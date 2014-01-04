/*
 * Exit_State_Event.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            1/3/14
 * Organization:    n8Tech
 *
 */

#ifndef EXIT_STATE_EVENT_H
#define EXIT_STATE_EVENT_H

#include "Event.h"

class Exit_State_Event :public Event{

public:
    Exit_State_Event();
    ~Exit_State_Event();
    
    virtual void process();
    
private:
    
};

#endif
