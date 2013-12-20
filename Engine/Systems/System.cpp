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
System::System(Game_Manager* gameManager){
    id_ = BASE_SYSTEM;
    game_ = gameManager;
    message_system_ = NULL;

    DEBUG_ = false;
    DEBUG_UPDATE_ = false;
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
bool System::check_requirements(Entity* entity){
	if(DEBUG_){
		Log::debug(id_ + ".check_requirements", "Entity: " + Numerical_Utilities::num_to_string(entity->get_id()));
	}
    map<string,int>::iterator ii;
    
    for (ii=requirements_.begin(); ii != requirements_.end(); ii++) {
        if ( entity->get_component(ii->first) == NULL) {
        	if(DEBUG_){
        		Log::debug(id_ + ".check_requirements", "FAIL");
			}
            return false;
        }
    }
    if(DEBUG_){
    	Log::debug(id_ + ".check_requirements", "PASS");
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
bool System::register_entity(Entity* newEntity){
	if(DEBUG_){
		Log::debug(id_ + ".register_entity", "Entity: " + Numerical_Utilities::num_to_string(newEntity->get_id()));
	}
    if (check_requirements(newEntity)) {
    	if(DEBUG_){
			Log::debug(id_ + ".register_entity", "PASS");
		}
        registered_entities_map_[newEntity->get_id()]= newEntity;
        return true;
    }
    else{
    	if(DEBUG_){
    		Log::debug(id_ + ".register_entity", "FAIL");
		}
        return false;
    }
    
    
}

/** Removes the specified entity from registered_entities_ vector.
 *
 *  @param ID The identifier of the entity to remove
 */
void System::remove_entity(int ID){
	if(DEBUG_){
		Log::debug(id_ + ".remove_entity", "Entity: " + ID);
	}
    registered_entities_map_.erase(ID);
}

/** Updates all registered entities when called.
 *  Should be overridden for derived classes
 */
void System::update(){
    if (DEBUG_UPDATE_) {
    	Log::debug(id_ + ".update", "");
        map<int, Entity*>::iterator ii;
        for (ii = registered_entities_map_.begin(); ii != registered_entities_map_.end(); ii++) {
        	Log::debug(id_ + ".update", "Updating Entity: " + Numerical_Utilities::num_to_string(ii->second->get_id()));
        }
    }
}
