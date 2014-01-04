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

class Show_Menu_Event :public Event{
    
public:
    Show_Menu_Event();
    ~Show_Menu_Event();
    
    virtual void process();
    
private:
    
};

#endif
