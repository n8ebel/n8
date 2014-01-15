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

class ExitStateEvent :public Event{

public:
    ExitStateEvent();
    ~ExitStateEvent();
    
    virtual void Process();
    
private:
    
};

#endif
