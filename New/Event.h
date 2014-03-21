/*
 *  Event.h
 *  goobar
 *
 *  Created by Nate Ebel on 3/19/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#ifndef EVENT_H
#define EVENT_H

#include <iostream>

#include "Enums.h"

namespace n8 {
    
/** Class to pass events between observable systems */
class Event{
public:
    Event(EEvent);
    
    EEvent GetType();
    
private:
    EEvent m_type; /** < The type of event.  Uses an enumerated type to differentiate event types > */
    
    
};
    
}

#endif /* defined(EVENT_H) */
