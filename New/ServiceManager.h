/*
 *  ServiceManager.h
 *  goobar
 *
 *  Created by Nate Ebel on 3/18/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#ifndef SERVICE_MANAGER_H
#define SERVICE_MANAGER_H

#include <iostream>
#include <map>

#include "Singleton.h"
#include "../Tools/Enums.h"

namespace n8{
    
class Service;

class ServiceManager : public Singleton<ServiceManager>{ 
public:
    ServiceManager();
    ~ServiceManager();
    
    void RegisterService(EService, Service*);
    void UnregisterService(EService);
    
    Service* GetService(EService);
    
private:
    std::map<EService,Service*> m_registeredServices;
};
    
}

#endif /* defined(SERVICE_MANAGER_H) */
