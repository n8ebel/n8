/*
 * Entity.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

#include <iostream>

#include "Entity.h"

using namespace std;

Entity::~Entity(){
    map<string, Component*>::iterator ii;
    cout << "Deleting Entity " << id_ << endl;
    for (ii = component_map_.begin(); ii != component_map_.end(); ii++) {
        delete ii->second;
    }
}

/** Adds the passed component to the map of entity components
 *
 *  @param newComponent the component to add
 *
 */
void Entity::add_component(Component* newComponent){
    cout << "Add Component.  ID= " << newComponent->get_id() << endl;
    component_map_[newComponent->get_id()] = newComponent;
    
    
}

void Entity::remove_component(string componentID){

}

/** Returns the specified component or null if it doesn't exisit
 *
 *  @param componentID The ID of the component to retrieve
 *
 */
Component* Entity::get_component(string componentID){
	map<string, Component*>::iterator ii = component_map_.find(componentID);
	if( ii != component_map_.end()){
		return component_map_[componentID];
	}
	else{
		return NULL;
	}
}

/** 
 *  @return the map of all registered components
 *
 */
map<string, Component*> Entity:: get_components(){
    return component_map_;
}
