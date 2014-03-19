/*
 *  Service.h
 *  goobar
 *
 *  Created by Nate Ebel on 3/19/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#ifndef SERVICE_H
#define SERVICE_H

#include <iostream>
#include <map>

#include "Enums.h"

namespace n8 {

class Service{
public:
    Service();
    virtual ~Service() = 0;
    
    void RegisterToObservice(EService,Service*);
    
protected:
    std::map<EService,Service*> m_observedServices;
};
    
}

#endif /* defined(SERVICE_H) */
