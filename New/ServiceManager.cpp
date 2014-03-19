/*
 *  ServiceManager.cpp
 *  goobar
 *
 *  Created by Nate Ebel on 3/18/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#include "ServiceManager.h"

/** Default Constructor */
n8::ServiceManager::ServiceManager(){
    
}

/** Destructor */
n8::ServiceManager::~ServiceManager(){
    
}

/** RegisterService
 *  Registers a provided service by adding it to a map of registered services using a provided enum value as a key.
 *
 *  @param EService An enum value to use as a map key
 *  @param Service* A pointer to a new service
 */
void n8::ServiceManager::RegisterService(EService key, Service* newService){
    m_registeredServices[key] = newService;
}

/** UnregisterService
 *  Unregisters a service by removing it from the map
 *
 *  @param EService An enum value to use as a map key
 */
void n8::ServiceManager::UnregisterService(EService key){
    std::map<EService,n8::Service*>::iterator ii = m_registeredServices.find(key);
    
    if(ii != m_registeredServices.end()){
        m_registeredServices.erase(ii);
    }
}

/** GetService
 *  Returns the service specified by the input key
 *
 *  @param EService An enum value to use as the lookup key for the map
 */
n8::Service* n8::ServiceManager::GetService(EService key){
    std::map<EService,n8::Service*>::iterator ii = m_registeredServices.find(key);
    
    if(ii != m_registeredServices.end()){
        return ii->second;
    }
    else{
        return NULL;
    }
}
