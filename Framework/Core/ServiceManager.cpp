/*
 *  ServiceManager.cpp
 *  goobar
 *
 *  Created by Nate Ebel on 3/18/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#include "ServiceManager.h"
#include "Log.h"

#define TAG "ServiceManager"

/** Default Constructor */
n8::ServiceManager::ServiceManager(){
    Log::Info(TAG, "Constructor");
}

/** Destructor */
n8::ServiceManager::~ServiceManager(){
    Log::Info(TAG, "Destructor");
}

/** RegisterService
 *  Registers a provided service by adding it to a map of registered services using a provided enum value as a key.
 *
 *  @param EService An enum value to use as a map key
 *  @param Service* A pointer to a new service
 */
void n8::ServiceManager::RegisterService(EService::Values key, Service* newService){
    m_registeredServices[key] = newService;
}

/** UnregisterService
 *  Unregisters a service by removing it from the map
 *
 *  @param EService An enum value to use as a map key
 */
void n8::ServiceManager::UnregisterService(EService::Values key){
    std::map<EService::Values,n8::Service*>::iterator ii = m_registeredServices.find(key);
    
    if(ii != m_registeredServices.end()){
        m_registeredServices.erase(ii);
    }
}

/** RemoveAllServices
 *  Removes and deletes all services from the map
 */
void n8::ServiceManager::RemoveAllServices(){
    std::map<EService::Values,n8::Service*>::iterator ii ;
    
    for (ii = m_registeredServices.begin(); ii!=m_registeredServices.end(); ii++) {
        Service* tmp = ii->second;
        ii->second = NULL;
        delete tmp;
    }
    m_registeredServices.clear();
}



/** GetService
 *  Returns the service specified by the input key
 *
 *  @param EService An enum value to use as the lookup key for the map
 */
n8::Service* n8::ServiceManager::GetService(EService::Values key){
    std::map<EService::Values,n8::Service*>::iterator ii = m_registeredServices.find(key);
    
    if(ii != m_registeredServices.end()){
        return ii->second;
    }
    else{
        return NULL;
    }
}
