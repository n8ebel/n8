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

void cEntity::add_component(cComponent* newComponent){
    componentMap[newComponent->get_id()] = newComponent;
    
}

void cEntity::remove_component(string componentID){

}

cComponent* cEntity::get_component(string componentID){
    return componentMap[componentID];
}

map<string, cComponent*> cEntity:: get_components(){
    return componentMap;
}
