/*
 * cEntity.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

#include "cEntity.h"
#include "cComponent.h"
#include <vector>
#include <map>
#include <iostream>

using namespace std;

cEntity::~cEntity(){
    map<string, cComponent*>::iterator ii;
    
    for (ii = componentMap.begin(); ii != componentMap.end(); ii++) {
        delete ii->second;
    }
}

cEntity::cEntity(){

}

cEntity::cEntity(int newID){
  id = newID;
}

int cEntity::get_id(){
  return id;
}

/** add_component
 *  
 *  newComponent- the component to add
 *
 *  Use -  Adds the passed component to the components map
 *
 */
void cEntity::add_component(cComponent* newComponent){
    cout << "Add Component.  ID= " << newComponent->get_id() << endl;
    componentMap[newComponent->get_id()] = newComponent;
    
    
}

void cEntity::remove_component(string componentID){

}

/** get_component
 *
 *  componentID- The ID of the component to retrieve
 *
 *  Use- Returns the specified component or null if it doesn't exisit
 *
 */
cComponent* cEntity::get_component(string componentID){
    return componentMap[componentID];
}

/** get_components
 *
 *  Use- returns the map of all added components
 *
 */
map<string, cComponent*> cEntity:: get_components(){
    return componentMap;
}
