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
    cout << "Checking requirements for " << id_ << endl;
    map<string,int>::iterator ii;
    
    for (ii=requirements_.begin(); ii != requirements_.end(); ii++) {
        cout << ii->first << endl;
        if ( entity->get_component(ii->first) == NULL) {
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
bool System::register_entity(Entity* newEntity){
    cout << "System.register_entity" << endl;
    if (check_requirements(newEntity)) {
        cout << "  entity passed check " << endl;
        //registered_entities_.push_back(newEntity);
        registered_entities_map_[newEntity->get_id()]= newEntity;
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
void System::remove_entity(int ID){
    /*
	int index = registered_entities_.size() -1 ;
	for(index; index >= 0; index--){
		if(registered_entities_[index]->get_id() == ID){
            cout << registered_entities_[index]->get_id() << endl;
            registered_entities_.erase(registered_entities_.begin()+index);
        }
	}
    */
    registered_entities_map_.erase(ID);

	

}

/** Updates all registered entities when called.
 *  Should be overridden for derived classes
 */
void System::update(){
    /*
    if (DEBUG_MODE && DEBUG_UPDATE) {
        cout << "    BASE_SYSTEM.Update()" << registered_entities_.size() << endl;
        for (int i = 0; i < registered_entities_.size(); i++) {
            cout << "      " << registered_entities_[i]->get_id() << endl;
        }
    }
     */
    if (DEBUG_MODE && DEBUG_UPDATE) {
        cout << "    BASE_SYSTEM.Update()" << registered_entities_map_.size() << endl;
        map<int, Entity*>::iterator ii;
        for (ii = registered_entities_map_.begin(); ii != registered_entities_map_.end(); ii++) {
            cout << "      " << ii->second->get_id() << endl;
        }
    }
}
