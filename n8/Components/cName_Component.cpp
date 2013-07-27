//
//  cName_Component.cpp
//  SDL_Test
//
//  Created by Nate Ebel on 7/21/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include "cName_Component.h"
#include <iostream>
#include <string>

using namespace std;

cName_Component::~cName_Component(){

}

cName_Component::cName_Component(){
    
}

cName_Component::cName_Component(string newID, string newName) : cComponent(newID){
    name = newName;
}

string cName_Component::get_name(){
    return name;
}