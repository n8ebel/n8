/*
 * System.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

#include <iostream>
#include "System.h"
#include "n8.h"
//#include "constants.h"
//#include "Name_Component.h"

using namespace std;


/** Default Destructor
 */
System::~System(){
    
}

/** Default Constructor <p>
 *  Sets id_ to a default 'BASE_SYSTEM' value
 */
System::System(){
    m_id = ID(BASE_SYSTEM);
}

/** Used to check if an entity contains all the neccessary components to be operated on
 *  by the system. <p>
 *  Called from register_entity
 *
 *  @param entity The entity object thats components are being checked
 *  @return True if the entity contains all the required components, False otherwise
 *
 *  @see Entity
 *  @see Component
 */
bool System::CheckRequirements(Entity* entity){
	
    map<ID,int>::iterator ii;
    
    for (ii=m_systemRequirements.begin(); ii != m_systemRequirements.end(); ii++) {
        if ( entity->GetComponent(ii->first) == NULL) {
        	
            return false;
        }
    }
    return true;
}


/** Registers an entity with the system.  If the entity contains all the required components
 *  the pointer to the entity is stored so it can later be operated on by the system.
 *
 *  @param newEntity A pointer to the entity to be registered
 *  @return True if the entity contains the needed components and was added to registered_entities_. False otherwise.
 *
 *  @see Entity
 *  @see Componenet
 */
bool System::RegisterEntity(Entity* newEntity){
	
    if (CheckRequirements(newEntity)) {
    	m_registeredEntities[newEntity->GetId()]= newEntity;
        return true;
    }
    else{
    	return false;
    }
}

/** Removes the specified entity from registered_entities_ vector.
 *
 *  @param ID The identifier of the entity to remove
 */
void System::UnregisterEntity(Entity* entityToUnregister){
	m_registeredEntities.erase(entityToUnregister->GetId());
}


