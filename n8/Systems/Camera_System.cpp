/*
 * Camera_System.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            8/5/13
 * Organization:    n8Tech
 *
*/

#include <iostream>
#include "Camera_System.h"
#include "n8.h"

Camera_System::~Camera_System(){
    
}

Camera_System::Camera_System(){
    entity_to_follow_ = NULL;
    camera_ = NULL;
}

bool Camera_System::register_entity_to_follow(Entity* newEntity){
    if (newEntity->get_component(POSITION) && newEntity->get_component(DRAWABLE)) {
        entity_to_follow_ = newEntity;
        return true;
    }
    
    return false;
    
}

bool Camera_System::register_camera_entity(Entity* newEntity){
    if (newEntity->get_component(POSITION) ) {
        camera_ = newEntity;
        return true;
    }
    
    return false;
}

void Camera_System::set_world_bounds(int w, int h){
    world_width_ = w;
    world_height_ = h;
}

void Camera_System::update(){
    int entityX = n8::get_position_component(entity_to_follow_)->get_position()->get_x();
    int entityY = n8::get_position_component(entity_to_follow_)->get_position()->get_y();
    int entW = n8::get_size_component(entity_to_follow_)->get_width();
    int entH = n8::get_size_component(entity_to_follow_)->get_height();
    int newX = entityX + .5*entW - n8::get_size_component(camera_)->get_width()/2;
    int newY = entityY + .5*entH - n8::get_size_component(camera_)->get_height()/2;
    
    if (newX < 0) {
        newX = 0;
    }
    if (newX > world_width_ -n8::get_size_component(camera_)->get_width()) {
        newX = world_width_ - n8::get_size_component(camera_)->get_width();
    }
    
    if (newY < 0) {
        newY = 0;
    }
    if (newY > world_height_ -n8::get_size_component(camera_)->get_height()) {
        newY = world_height_ -n8::get_size_component(camera_)->get_height();
    }
    
    n8::get_position_component(camera_)->get_position()->set_x(newX);
    n8::get_position_component(camera_)->get_position()->set_y(newY);
}


