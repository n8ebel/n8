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

using namespace std;

const string ID = "BASE_SYSTEM";

cSystem::~cSystem(){
    
}

cSystem::cSystem(){
    
}

bool cSystem::check_requirements(cEntity* entity){

    return false;
}

void cSystem::register_entity(cEntity* newEntity){
    
}

void cSystem::update(){
    
}