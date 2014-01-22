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
    map<ID, Component*>::iterator ii;
    cout << "Deleting Entity " << m_id->GetId() << endl;
    for (ii = m_componentMap.begin(); ii != m_componentMap.end(); ii++) {
        delete ii->second;
    }
}

/** Adds the passed component to the map of entity components
 *
 *  @param newComponent the component to add
 *
 */
void Entity::AddComponent(Component* newComponent){
    cout << "Add Component.  ID= " << COMPONENT_IDS[newComponent->GetId().GetId()] << endl;
    if (newComponent) {
        m_componentMap[newComponent->GetId()] = newComponent;
    }
    else{
        Log::Info(ENTITY, "Failed to add component.  Component was null.");
    }
    
    
    
}

/** Removes a specified component from the entity
 *
 *  @param componentID The identifier of the component to be removed
 */
void Entity::RemoveComponent(string componentID){

}

/** Returns the specified component or null if it doesn't exisit
 *
 *  @param componentID The ID of the component to retrieve
 *
 */
Component* Entity::GetComponent(ID componentID){
	map<ID, Component*>::iterator ii = m_componentMap.find(componentID);
	if( ii != m_componentMap.end()){
		return m_componentMap[componentID];
	}
	else{
        Log::Debug("Component", "Didn't find " + COMPONENT_IDS[componentID.GetId()] + " component");
		return NULL;
	}
}

/** 
 *  @return the map of all registered components
 *
 */
map<ID, Component*> Entity:: GetComponents(){
    return m_componentMap;
}
