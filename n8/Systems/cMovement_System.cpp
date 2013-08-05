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
    std::cout << "cMovement_System.update()"<<std::endl;
}

void cMovement_System::key_right(){
    std::cout << "cMovement_System.key_right()"<<std::endl;
    
    for (int i = 0; i < registered_entities.size(); i++) {
        ((cPosition_Component*)registered_entities[i]->get_component(POSITION))->update_position(5, 0);
    }
}
void cMovement_System::key_down(){
    
}
void cMovement_System::key_left(){
    
}
void cMovement_System::key_up(){
    
}