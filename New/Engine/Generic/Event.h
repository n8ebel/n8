/*
 * Event.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            1/3/14
 * Organization:    n8Tech
 *
 */

#ifndef EVENT_H
#define EVENT_H

#include "Object.h"

/** Base event class to handle different game events */
class Event : public Object{

public:
    virtual void Process() = 0;
    
private:
    
};

#endif
