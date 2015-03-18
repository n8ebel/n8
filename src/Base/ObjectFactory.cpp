/*
 *  ObjectFactory.cpp
 *  goobar
 *
 *  Created by Nate Ebel on 3/18/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#include "../Headers/ObjectFactory.h"

int n8::ObjectFactory::m_nextId = 0;

/** Used to get the next available unique integer id for a created entity.  When called nextid_ is incremented so the return values are always unique.
 *
 *  @return The next available id number
 */
int n8::ObjectFactory::GetNextId(){
    m_nextId++;
    return m_nextId;
}