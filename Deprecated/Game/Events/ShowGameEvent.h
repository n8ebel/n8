/*
 * ShowGameEvent.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            1/3/14
 * Organization:    n8Tech
 *
 */

#ifndef SHOW_GAME_EVENT_H
#define SHOW_GAME_EVENT_H

#include "Event.h"

class ShowGameEvent :public Event{
    
public:
    ShowGameEvent();
    ~ShowGameEvent();
    
    virtual void Process();
    
private:
    
};

#endif
