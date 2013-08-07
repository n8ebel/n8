/*
 * cPosition_Component.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

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

int cPosition_Component::get_x(){
    return position->get_x();
}

int cPosition_Component::get_y(){
    return position->get_y();
}


void cPosition_Component::update_position(int xOffset, int yOffset){
    position->add_x(xOffset);
    position->add_y(yOffset);
}
