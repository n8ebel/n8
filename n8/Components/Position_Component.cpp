/*
 * Position_Component.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

#include <iostream>
#include "Component.h"
#include "Position_Component.h"
#include "Point.h"

Position_Component::~Position_Component(){
    delete position_;
}

Position_Component::Position_Component(string newID, Point* newPosition) : Component(newID){
    position_ = newPosition;
}

Position_Component::Position_Component(string newID, int initX, int initY) : Component(newID){
    position_ = new Point(initX, initY);
}

Point* Position_Component::get_position(){
    return position_;
}

int Position_Component::get_x(){
    return position_->get_x();
}

int Position_Component::get_y(){
    return position_->get_y();
}


void Position_Component::update_position(int xOffset, int yOffset){
    position_->add_x(xOffset);
    position_->add_y(yOffset);
}
