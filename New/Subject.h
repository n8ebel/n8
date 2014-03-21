/*
 *  Subject.h
 *  goobar
 *
 *  Created by Nate Ebel on 3/19/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#ifndef SUBJECT_H
#define SUBJECT_H

#include <iostream>
#include <vector>

#include "Observer.h"
#include "Event.h"

namespace n8{
    
/** Subjects inform other systems that an event has occured */
class Subject{
public:
    void AddObserver(Observer* observer);
    void RemoveObserver(Observer* observer);
    
    void Notify(Event*);

private:
    std::vector<Observer*> m_observers;
    
};
    
}

#endif /* defined(SUBJECT_H) */
