/*
 * SystemManager.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            1/17/14
 * Organization:    n8Tech
 *
 */

#include "SystemManager.h"

using namespace std;

SystemManager::SystemManager(){
    
}

SystemManager::~SystemManager(){
    
}

/** Adds a pointer to a system to a map of registered systems
 *  Allows for a central point of access to all systems
 *
 *  @param newSystemKey The identifier key for the new system
 *  @param newSystem The pointer to the system to be registered
 *
 *  @return True if the key didn't already exist in the map, False otherwise
 */
bool SystemManager::RegisterSystem(string newSystemKey, System* newSystem){
    if (newSystem) {
        m_registeredSystems[newSystemKey] = newSystem;
        return true;
    }
    else{
        return false;
    }
}

/** Removes a pointer to a system from the map of registered systems
 *
 *  @param systemKey The map key for the system to be removed from the map
 */
void SystemManager::UnregisterSystem(string systemKey){
    
}

/** Informs registered game systems that the specified entity needs to be operated on.
 *  The entity is only registered with a system if it meets that system's requirements
 *  
 *  @param entityToRegister The the entity to register
 */
void SystemManager::RegisterEntity(Entity* entityToRegister){
    map<string,System*>::iterator ii;
    for (ii = m_registeredSystems.begin(); ii != m_registeredSystems.end(); ii++) {
        ii->second->RegisterEntity(entityToRegister);
    }
}

void SystemManager::UnregisterEntity(Entity* entityToUnregister){
    map<string,System*>::iterator ii;
    for (ii = m_registeredSystems.begin(); ii != m_registeredSystems.end(); ii++) {
        ii->second->UnregisterEntity(entityToUnregister);
    }
}


/** Calls the Update method on all registered systems */
void SystemManager::Update(Uint32){
    
}

/** Returns a pointer to the specified system
 *
 *  @param systemKey The string key to look up the system by
 *
 *  @return Pointer to the specified system, or null
 */
System* SystemManager::GetSystem(string systemKey){
    return m_registeredSystems[systemKey];
}