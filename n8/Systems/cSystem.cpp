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

void cSystem::connect_message_handler(cMessage_Handler* msgr){
    message_system = msgr;
}

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

void cSystem::register_entity(cEntity* newEntity){
    
    registered_entities.push_back(newEntity);
}

void cSystem::update(){
    cout << "    BASE_SYSTEM.Update()" << registered_entities.size() << endl;
    for (int i = 0; i < registered_entities.size(); i++) {
        cout << "      " << registered_entities[i]->get_id() << endl;
    }
}