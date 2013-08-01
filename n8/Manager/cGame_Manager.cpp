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
#include "constants.h"


#include "cGame_Manager.h"


const int cGame_Manager::LOADING_SCREEN = 1;
const int cGame_Manager::MENU = 2;
const int cGame_Manager::WORLD_VIEW = 3;

cGame_Manager::~cGame_Manager(){
    
}

cGame_Manager::cGame_Manager(){
    message_handler = NULL;
}

cGame_Manager::cGame_Manager(string resource_config, int screenW, int screenH){
    
}

/** add_system
 *  
 *  ID- The string ID specifier for the system to add
 *  newSystem- The system pointer
 *
 *  Use- Adds a new system to the manager
 *       This registers the system with the game manager
 *       It also allows the game manager to pass a reference
 *         to the message system object to the system
 *
 */
bool cGame_Manager::add_system(string ID, cSystem* newSystem){
    map<string,cSystem*>::iterator ii = registered_systems.find(ID);
    
    if(ii != registered_systems.end()){
        return false;
    }
    else{
        newSystem->connect_message_handler(message_handler);
        registered_systems[ID] = newSystem;
    }
    
    return true;
}

/** get_system
 *
 *  ID- The system specifier
 *  
 *  Use- Returns a pointer to the specified system or NULL
 *       If the system is not registered with the game manager
 *
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

/**  register_entity
 *
 *  newEntity- the new entity to register with the game manager
 *  
 *  Use- Registers an entity with the game system.
 *       Takes each system and registers the entity with it
 *          if it meets the system requirements.
 *
 */
cEntity* cGame_Manager::register_entity(cEntity* newEntity){
    
    
    registered_entities[newEntity->get_id()] = newEntity;
    
    map<string,cSystem*>::iterator ii;
    for( ii=registered_systems.begin(); ii != registered_systems.end(); ii++){
        ii->second->register_entity(newEntity);
    }
    
    return newEntity;
}


/** get_entity
 *
 *  ID- The id of the entity to return
 *
 *  Use- If an entity with the specified ID exists it is returned
 *       If the ID doesn't exist, NULL is returned
 *
 */
cEntity* cGame_Manager::get_entity(int ID){
    map<int, cEntity*>::iterator ii = registered_entities.find(ID);
    
    if ( ii == registered_entities.end() ) {
        return NULL;
    }
    else{
        return ii->second;
    }
}

/** create_system
 *
 *  ID- the string specifier for the system to create and add to the system
 *
 *  Use- Creates a new system object.
 *       The system type is specified by the passed argument.
 *       The system is then added to the game manager registered systems map
 *       The method returns a pointer to the created object.
 */
cSystem* cGame_Manager::create_system(string ID){
    if (ID == BASE_SYSTEM) {
        cSystem* newSystem = new cSystem();
        newSystem->connect_message_handler(message_handler);
        if( add_system(ID, newSystem) ){
            return newSystem;
        }
        else{
            return NULL;
        }
    }
    else if(ID == RENDER_SYSTEM){
        cRender_System* newSystem = new cRender_System();
        newSystem->connect_message_handler(message_handler);
        if( add_system(ID, newSystem) ){
            return newSystem;
        }
        else{
            return NULL;
        }
    }
    
    return NULL;
}

/** get_message_handler
 *
 *  Use- returns a pointer to the message_handler
 *
 */
cMessage_Handler* cGame_Manager::get_message_handler(){
    return message_handler;
}

/** create_user_entity
 *
 *  id-         the id for the new user entity
 *  initName-   the name of the new user entity
 *  initX-      the initial x position
 *  intiY-      the initial y position
 *  sprite-     the sprite to use to draw the entity
 *
 *  Use-    Creates a new user entity
 *          Using this method ensures the proper components are added to the user entity
 *          Added components include:
 *              Name
 *              Position
 *              Drawable
 *
 */
cEntity* cGame_Manager::create_user_entity(int id, string initName, int initX, int initY, cSprite* sprite){
    
    
    cEntity* foo = new cEntity(id);
    cName_Component* name = new cName_Component(NAME, initName);
    cPosition_Component* position = new cPosition_Component(POSITION, initX, initY);
    
    cDrawable_Component* drawable = new cDrawable_Component(DRAWABLE, sprite);    
    
    foo->add_component(name);
    foo->add_component(position);
    foo->add_component(drawable);
    
    return foo;
    
}


