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
    requirements[DRAWABLE] = 1;
    requirements[POSITION] = 1;
    requirements[CONTROLLABLE] = 1;
    ID = MOVEMENT_SYSTEM;
}

void cMovement_System::set_world_bounds(int w, int h){
    world_width = w;
    world_height = h;
}

bool cMovement_System::inside_world_bounds(cEntity* ent, int xOffset, int yOffset){
    int curX = n8::get_position_component(ent)->get_x();
    int curY = n8::get_position_component(ent)->get_y();
    int width = n8::get_size_component(ent)->get_width();
    int height = n8::get_size_component(ent)->get_height();
    
    cout << "world width: " << world_width << endl;
    cout << "id: " << ent->get_id() << endl;
    cout << "left: " << curX << endl;
    cout << "right: " << curX+width << endl;
    
    
    
    if ( (curX+xOffset) >= 0 && (curX + width+xOffset) <= world_width){
        cout << "x okay" << endl;
        if( (curY+yOffset) >= 0 && (curY + height+yOffset) <= world_height){
            cout << "y okay" << endl;
            return true;
        }
        else{
            return false;
        }
    } 
    else{
        return false;
    }
    
}

void cMovement_System::update(){
    
}

void cMovement_System::right(){
    
    for (int i = 0; i < registered_entities.size(); i++) {
        if( inside_world_bounds(registered_entities[i], 5, 0)){
            ((cPosition_Component*)registered_entities[i]->get_component(POSITION))->update_position(5, 0);
        }
    }
}
void cMovement_System::down(){
    for (int i = 0; i < registered_entities.size(); i++) {
        if( inside_world_bounds(registered_entities[i], 0, 5)){
            ((cPosition_Component*)registered_entities[i]->get_component(POSITION))->update_position(0, 5);
        }
    }
}
void cMovement_System::left(){
    for (int i = 0; i < registered_entities.size(); i++) {
        if( inside_world_bounds(registered_entities[i], -5, 0)){
            ((cPosition_Component*)registered_entities[i]->get_component(POSITION))->update_position(-5, 0);
        }
    }
}
void cMovement_System::up(){
    for (int i = 0; i < registered_entities.size(); i++) {
        if( inside_world_bounds(registered_entities[i], 0, -5)){
            ((cPosition_Component*)registered_entities[i]->get_component(POSITION))->update_position(0, -5);
        }
    }
}