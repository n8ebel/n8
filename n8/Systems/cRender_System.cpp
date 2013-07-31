/*
 * cRender_System.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/30/13
 * Organization:    n8Tech
 *
*/

#include "cRender_System.h"
#include "cName_Component.h"
#include <iostream>

using namespace std;

cRender_System::~cRender_System(){
    
}

cRender_System::cRender_System(){
    requirements[DRAWABLE] = 1;
    requirements[POSITION] = 1;
    ID = BASE_SYSTEM;
}

void cRender_System::render(){
    
}

void cRender_System::update(){
    cout << "    RENDER_SYSTEM.Update()" << registered_entities.size() << endl;
    for (int i = 0; i < registered_entities.size(); i++) {
        cName_Component* name = (cName_Component*)registered_entities[i]->get_component(NAME);
        if (name == NULL) {
            cout << "      " << registered_entities[i]->get_id() << endl;
        }
        else{
            cout << "      " << name->get_name() << endl;   
        }
    }
}