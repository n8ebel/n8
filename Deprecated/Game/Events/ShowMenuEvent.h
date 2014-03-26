/*
 * Show_Menu_Event.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            1/3/14
 * Organization:    n8Tech
 *
 */

#ifndef SHOW_MENU_EVENT_H
#define SHOW_MENU_EVENT_H

#include "Event.h"

class ShowMenuEvent :public Event{
    
public:
    ShowMenuEvent();
    ~ShowMenuEvent();
    
    virtual void Process();
    
private:
    
};

#endif
