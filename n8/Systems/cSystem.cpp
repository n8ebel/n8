/*
 * cSystem.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

#include <iostream>
#include "cSystem.h"
//#include "constants.h"
#include "cName_Component.h"

using namespace std;



cSystem::~cSystem(){
    
}

cSystem::cSystem(){
    //requirements[NAME] = 1;
    ID = BASE_SYSTEM;
}

/** connect_message_handler
 *
 *  msgr-   the message handler pointer from the game manager to store a reference to
 *
 *  Use-    Using this allows the system to use the same message_handler as everything else
 *
 */
void cSystem::connect_message_handler(cMessage_Handler* msgr){
    message_system = msgr;
}

/** check_requirements
 *
 *  entity- the entity to check if it has the requirements to register to the system
 *
 *  Use-    If the passed entity contains all the required components the method returns true
 *          Required components are specified in the 'requirements' map
 *
 */
bool cSystem::check_requirements(cEntity* entity){
    cout << "Checking requirements for " << ID << endl;
    map<string,int>::iterator ii;
    
    for (ii=requirements.begin(); ii != requirements.end(); ii++) {
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
bool cSystem::register_entity(cEntity* newEntity){
    if (check_requirements(newEntity)) {
        registered_entities.push_back(newEntity);
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
void cSystem::update(){
    if (DEBUG_MODE) {
        cout << "    BASE_SYSTEM.Update()" << registered_entities.size() << endl;
        for (int i = 0; i < registered_entities.size(); i++) {
            cout << "      " << registered_entities[i]->get_id() << endl;
        }
    }
}