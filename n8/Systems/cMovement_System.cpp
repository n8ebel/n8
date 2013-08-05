/*
 * cMovement_System.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            8/4/13
 * Organization:    n8Tech
 *
*/

#include <iostream>
#include "n8.h"
#include "cMovement_System.h"


cMovement_System::~cMovement_System(){
    
}
cMovement_System::cMovement_System(){
    
}

void cMovement_System::update(){
    
}

void cMovement_System::right(){
    
    for (int i = 0; i < registered_entities.size(); i++) {
        ((cPosition_Component*)registered_entities[i]->get_component(POSITION))->update_position(5, 0);
    }
}
void cMovement_System::down(){
    for (int i = 0; i < registered_entities.size(); i++) {
        ((cPosition_Component*)registered_entities[i]->get_component(POSITION))->update_position(0, 5);
    }
}
void cMovement_System::left(){
    for (int i = 0; i < registered_entities.size(); i++) {
        ((cPosition_Component*)registered_entities[i]->get_component(POSITION))->update_position(-5, 0);
    }
}
void cMovement_System::up(){
    for (int i = 0; i < registered_entities.size(); i++) {
        ((cPosition_Component*)registered_entities[i]->get_component(POSITION))->update_position(0, -5);
    }
}