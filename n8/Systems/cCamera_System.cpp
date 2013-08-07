/*
 * cCamera_System.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            8/5/13
 * Organization:    n8Tech
 *
*/

#include <iostream>
#include "cCamera_System.h"
#include "n8.h"

cCamera_System::~cCamera_System(){
    
}

cCamera_System::cCamera_System(){
    entity_to_follow = NULL;
    camera = NULL;
}

bool cCamera_System::register_entity_to_follow(cEntity* newEntity){
    if (newEntity->get_component(POSITION) && newEntity->get_component(DRAWABLE)) {
        entity_to_follow = newEntity;
        return true;
    }
    
    return false;
    
}

bool cCamera_System::register_camera_entity(cEntity* newEntity){
    if (newEntity->get_component(POSITION) ) {
        camera = newEntity;
        return true;
    }
    
    return false;
}

void cCamera_System::update(){
    //int newX = n8::get_position_component(entity_to_follow)->get_position()->get_x() - n8::get_drawable_component(screen)->get_image()->w/2;
    //int newY = n8::get_position_component(entity_to_follow)->get_position()->get_y() - n8::get_drawable_component(screen)->get_image()->h/2;
    int newX = n8::get_position_component(entity_to_follow)->get_position()->get_x() - n8::get_size_component(camera)->get_width()/2;
    int newY = n8::get_position_component(entity_to_follow)->get_position()->get_y() - n8::get_size_component(camera)->get_height()/2;
    
    if (newX < 0) {
        newX = 0;
    }
    
    if (newY < 0) {
        newY = 0;
    }
    
    n8::get_position_component(camera)->get_position()->set_x(newX);
    n8::get_position_component(camera)->get_position()->set_y(newY);
}


