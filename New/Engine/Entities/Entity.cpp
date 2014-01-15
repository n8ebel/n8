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
    cout << "Deleting Entity " << m_id << endl;
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
    cout << "Add Component.  ID= " << newComponent->GetId() << endl;
    m_componentMap[newComponent->GetId()] = newComponent;
    
    
}

void Entity::RemoveComponent(string componentID){

}

/** Returns the specified component or null if it doesn't exisit
 *
 *  @param componentID The ID of the component to retrieve
 *
 */
Component* Entity::GetComponent(string componentID){
	map<string, Component*>::iterator ii = m_componentMap.find(componentID);
	if( ii != m_componentMap.end()){
		return m_componentMap[componentID];
	}
	else{
		return NULL;
	}
}

/** 
 *  @return the map of all registered components
 *
 */
map<string, Component*> Entity:: GetComponents(){
    return m_componentMap;
}
