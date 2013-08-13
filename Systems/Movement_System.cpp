/*
 * Movement_System.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            8/4/13
 * Organization:    n8Tech
 *
*/

#include <iostream>
#include "n8.h"
#include "Movement_System.h"

/** Default Destructor **/
Movement_System::~Movement_System(){
    
}

/** Default Constructor <p>
 *  Defines the system requirements of DRAWABLE, CONTROLLABLE, and POSITION and sets id_ to MOVEMENT_SYSTEM.  
 */
Movement_System::Movement_System(Game_Manager* gameManager){
    requirements_[DRAWABLE] = 1;
    requirements_[POSITION] = 1;
    requirements_[CONTROLLABLE] = 1;
    id_ = MOVEMENT_SYSTEM;
    game_ = gameManager;
}

/** Determines if an entity can safely move in a direction without extending outside the bounds of the current game world.  Used to verify whether an entity can move in a direction when told to.  The passed x and y offset are added to the entity's current position to determine whether that move will move the entity outside the world bound.
 *
 *  @param ent The entity that is being moved
 *  @param xOffset An amount that the entity is trying to move in the x direction
 *  @param yOffset An amount that the entity is trying to move in the y direction
 *  @return True if offsets don't move the entity outside the world bounds.  False otherwise.
 *
 *  @see Entity
 *  @see Position_Component
 *  @see Size_Component
 */
bool Movement_System::inside_world_bounds(Entity* ent, int xOffset, int yOffset){
    int curX = n8::get_position_component(ent)->get_x();
    int curY = n8::get_position_component(ent)->get_y();
    int width = n8::get_position_component(ent)->get_width();
    int height = n8::get_position_component(ent)->get_height();
    
    cout << "world width: " << world_width_ << endl;
    cout << "id: " << ent->get_id() << endl;
    cout << "left: " << curX << endl;
    cout << "right: " << curX+width << endl;
    
    
    
    if ( (curX+xOffset) >= 0 && (curX + width+xOffset) <= world_width_){
        cout << "x okay" << endl;
        if( (curY+yOffset) >= 0 && (curY + height+yOffset) <= world_height_){
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

void Movement_System::update(){
    
}

void Movement_System::right(){
    
    for (int i = 0; i < registered_entities_.size(); i++) {
        if( inside_world_bounds(registered_entities_[i], 5, 0)){
            ((Position_Component*)registered_entities_[i]->get_component(POSITION))->update_position(5, 0);
            ((Interaction_System*)game_->get_system(INTERACTION_SYSTEM))->handle_interaction(PROJECTILE_SYSTEM, registered_entities_[0], registered_entities_[0]);
        }
    }
}
void Movement_System::down(){
    for (int i = 0; i < registered_entities_.size(); i++) {
        if( inside_world_bounds(registered_entities_[i], 0, 5)){
            ((Position_Component*)registered_entities_[i]->get_component(POSITION))->update_position(0, 5);
        }
    }
}
void Movement_System::left(){
    for (int i = 0; i < registered_entities_.size(); i++) {
        if( inside_world_bounds(registered_entities_[i], -5, 0)){
            ((Position_Component*)registered_entities_[i]->get_component(POSITION))->update_position(-5, 0);
        }
    }
}
void Movement_System::up(){
    for (int i = 0; i < registered_entities_.size(); i++) {
        if( inside_world_bounds(registered_entities_[i], 0, -5)){
            ((Position_Component*)registered_entities_[i]->get_component(POSITION))->update_position(0, -5);
        }
    }
}
