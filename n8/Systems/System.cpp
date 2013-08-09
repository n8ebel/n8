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



System::~System(){
    
}

System::System(){
    //requirements[NAME] = 1;
    id_ = BASE_SYSTEM;
}

/** connect_message_handler_
 *
 *  msgr-   the message handler pointer from the game manager to store a reference to
 *
 *  Use-    Using this allows the system to use the same message_handler_ as everything else
 *
 */
void System::connect_message_handler_(Message_Handler* msgr){
    message_system_ = msgr;
}

/** check_requirements
 *
 *  entity- the entity to check if it has the requirements to register to the system
 *
 *  Use-    If the passed entity contains all the required components the method returns true
 *          Required components are specified in the 'requirements' map
 *
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

/** register_entity
 *
 *  newEntity-  the new entity to attempt to register with the system
 *
 *  Use-    The entity is checked to see if it has the required components
 *          If the components are all their, the entity is added to the 
 *            registered entities vector
 *
 */
bool System::register_entity(Entity* newEntity){
    cout << "System.register_entity" << endl;
    if (check_requirements(newEntity)) {
        cout << "  entity passed check " << endl;
        registered_entities_.push_back(newEntity);
        return true;
    }
    else{
        return false;
    }
    
    
}

/** update
 *
 *  Use-    This is the base update method for all systems
 *          Can be used to update game logic on any component data
 *
 */
void System::update(){
    if (DEBUG_MODE && DEBUG_UPDATE) {
        cout << "    BASE_SYSTEM.Update()" << registered_entities_.size() << endl;
        for (int i = 0; i < registered_entities_.size(); i++) {
            cout << "      " << registered_entities_[i]->get_id() << endl;
        }
    }
}