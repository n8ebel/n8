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
#include "Service.h"
#include "../Core/Enums.h"

namespace n8{

/** Provides a global access point to registered services.  This gives a less coupled way of providing access to game systems.  Services are registered with the ServiceManager during the game's initialization.
 */
class ServiceManager : public Singleton<ServiceManager>{ 
public:
    ServiceManager();
    ~ServiceManager();
    
    void RegisterService(EService::Values, Service*);
    void UnregisterService(EService::Values);
    
    void RemoveAllServices();
    
    Service* GetService(EService::Values);
    
private:
    std::map<EService::Values,Service*> m_registeredServices;
};
    
}

#endif /* defined(SERVICE_MANAGER_H) */
