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
    
class Event{
public:
    Event(EEvent);
    
    EEvent GetType();
    
private:
    EEvent m_type;
    
    
};
    
}

#endif /* defined(EVENT_H) */
