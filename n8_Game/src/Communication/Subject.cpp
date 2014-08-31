/*
 *  Subject.cpp
 *  goobar
 *
 *  Created by Nate Ebel on 3/19/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#include "Subject.h"

/** AddObserver
 *  Adds a pointer to a list of observers to it can be notified of events
 *
 *  @param observer The observer to add to the list
 */
void n8::Subject::AddObserver(Observer* observer){
    m_observers.push_back(observer);
}

/** RemoveObserver
 *  Removes an observer from the observers list if it is present
 *
 *  @param observer The observer to remove from the observers list
 */
void n8::Subject::RemoveObserver(Observer* observer){
    std::vector<Observer*>::iterator ii;
    
    for (ii = m_observers.begin(); ii != m_observers.end(); ii++) {
        if(*ii == observer){
            break;
        }
    }
    if(ii != m_observers.end()){
        m_observers.erase(ii);
    }
}

/** Notify
 *  Informs observers that some event has occured so they can respond accordingly
 *
 *  @param event The event that has occured and can be handled
 */
void n8::Subject::Notify(n8::Event* event){
    for (int i = 0; i < m_observers.size(); i++) {
        m_observers[i]->OnNotify(event);
    }
}