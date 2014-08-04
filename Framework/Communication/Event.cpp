/*
 *  Event.cpp
 *  goobar
 *
 *  Created by Nate Ebel on 3/19/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#include "Event.h"

/** Constructor
 *  Creates the event and sets its type
 *
 *  @param type The type of the event
 */
n8::Event::Event(int type){
    m_type = type;
}

/** GetType
 *  Used to get the type of an event so it can be properly handled
 *
 *  @return The type of the event
 */
int n8::Event::GetType(){
    return m_type;
}