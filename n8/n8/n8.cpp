//
//  n8.cpp
//  SDL_Test
//
//  Created by Nate Ebel on 7/21/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include "n8.h"
#include <iostream>
#include <string>


using namespace std;

// Static constants for component identifiers
const string n8::NAME = "NAME";
const string n8::DRAWABLE = "DRAWABLE";
const string n8::POSITION = "POSITION";
const string n8::INTERACTABLE = "INTERACTABLE";

// Static constants for system identifiers
const string n8::RENDER_SYSTEM = "RENDER_SYSTEM";



// Static counter for unique entity ID's
int n8::nextID = 0;

/* default constructor 
 * 
*/ 
n8::n8(){
    
}

cEntity* n8::create_user_entity(int id, string initName, int initX, int initY){
    cEntity* foo = new cEntity(id);
    
    foo->add_component(new cName_Component(n8::NAME, initName));
    foo->add_component(new cPosition_Component(n8::POSITION, initX, initY));
    
    return foo;
    
}

cName_Component* n8:: get_name_component(cEntity* entity){
    return (cName_Component*)entity->get_components()[NAME];
}

cPosition_Component* n8:: get_position_component(cEntity* entity){
    return (cPosition_Component*)entity->get_components()[POSITION];
}