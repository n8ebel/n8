/*
 * cGame_Manager.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

#include <iostream>
#include "n8.h"


#include "cGame_Manager.h"

const int cGame_Manager::LOADING_SCREEN = 1;
const int cGame_Manager::MENU = 2;
const int cGame_Manager::WORLD_VIEW = 3;

cGame_Manager::~cGame_Manager(){
    
}

cGame_Manager::cGame_Manager(){
    
}

cGame_Manager::cGame_Manager(string resource_config, int screenW, int screenH){
    
}

/*  add_system
   
    Adds a new system to the manager
    This registers the system with the game manager
    It also allows the game manager to pass a reference
     to the message system object to the system
*/
bool cGame_Manager::add_system(string ID, cSystem* newSystem){
    map<string,cSystem*>::iterator ii = registered_systems.find(ID);
    
    if(ii != registered_systems.end()){
        return false;
    }
    else{
        registered_systems[ID] = newSystem;
    }
    
    return true;
}

/* get_system
 
    Returns a pointer to the specified system or NULL
      if the system is not registered with the game
      manager
*/
cSystem* cGame_Manager::get_system(string ID){
    map<string,cSystem*>::iterator ii = registered_systems.find(ID);
    
    if ( ii == registered_systems.end() ) {
        return NULL;
    }
    else{
        return ii->second;
    }
}

/*  register_entity
 
    Registers an entity with the game system.
    Takes each system and registers the entity with it
      if it meets the system requirements.
*/
cEntity* cGame_Manager::register_entity(cEntity* newEntity){
    //add entity to registered_entities
    
    // for each system in registered_systems
        // check if entity matches system requirements
            // if YES then register with system
    
    return NULL;
}

cEntity* cGame_Manager::get_entity(int ID){
    map<int, cEntity*>::iterator ii = registered_entities.find(ID);
    
    if ( ii == registered_entities.end() ) {
        return NULL;
    }
    else{
        return ii->second;
    }
}

/*  create_system
 
    Creates a new system object.
    The system type is specified by the passed argument.
    The method returns a pointer to the created object.
 */
cSystem* cGame_Manager::create_system(string ID){
    if (ID == n8::BASE_SYSTEM) {
        cSystem* newSystem = new cSystem();
        if( add_system(ID, newSystem) ){
            return newSystem;
        }
        else{
            return NULL;
        }
    }
    
    return NULL;
}

/*  get_message_handler
 
    Returns a pointer to the game's message handler
 */
cMessage_Handler* cGame_Manager::get_message_handler(){
    return messanger;
}


