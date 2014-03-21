/*
 *  Subject.cpp
 *  goobar
 *
 *  Created by Nate Ebel on 3/19/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#include "Subject.h"

void n8::Subject::AddObserver(Observer* observer){
    m_observers.push_back(observer);
}

void n8::Subject::RemoveObserver(Observer* observer){
    std::vector<Observer*>::iterator ii;
    
    for (ii = m_observers.begin(); ii != m_observers.end(); ii++) {
        if(*ii == observer){
            break;
        }
    }
    m_observers.erase(ii);
}

void n8::Subject::Notify(n8::Event* event){
    for (int i = 0; i < m_observers.size(); i++) {
        m_observers[i]->OnNotify(event);
    }
}