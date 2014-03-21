/*
 *  Event.cpp
 *  goobar
 *
 *  Created by Nate Ebel on 3/19/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#include "Event.h"

n8::Event::Event(EEvent type){
    m_type = type;
}

EEvent n8::Event::GetType(){
    return m_type;
}