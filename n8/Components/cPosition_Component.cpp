//
//  cPosition_Component.cpp
//  SDL_Test
//
//  Created by Nate Ebel on 7/22/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "cComponent.h"
#include "cPosition_Component.h"
#include "cPoint.h"

cPosition_Component::~cPosition_Component(){
    delete position;
}

cPosition_Component::cPosition_Component(string newID, cPoint* newPosition) : cComponent(newID){
    position = newPosition;
}

cPosition_Component::cPosition_Component(string newID, int initX, int initY) : cComponent(newID){
    position = new cPoint(initX, initY);
}

cPoint* cPosition_Component::get_position(){
    return position;
}
