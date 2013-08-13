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

/** Default Destructor **/
Camera_System::~Camera_System(){
    
}

/** Default Constructor <p>
 *  Initializes entity_to_follow_ and camera_ to NULL
 */
Camera_System::Camera_System(Game_Manager* gameManager){
    entity_to_follow_ = NULL;
    camera_ = NULL;
}

/** Stores a pointer to an entity that the camera should follow.  If the passed entity has a POSITION and DRAWABLE component a pointer to the entity is stored in entity_to_follow_.  This allows the system to update the camera position based on that entity's position.
 *
 *  @param newEntity The entity that the camera should follow
 *  @return True if the passed entity object has a POSITION and DRAWABLE component, False otherwise
 *
 *  @see Position_Component
 *  @see Drawable_Component
 */
bool Camera_System::register_entity_to_follow(Entity* newEntity){
    if (newEntity->get_component(POSITION) && newEntity->get_component(DRAWABLE)) {
        entity_to_follow_ = newEntity;
        return true;
    }
    
    return false;
    
}

/** Stores a pointer to a camera entity.  This allows the system to update the position of the camera based on a registered entity's current position.  This allows the camera to follow the entity around the game world
 *
 *  @param newEntity The camera entity.  The entity must have a POSITION component
 *  @return True if the entity has the required component, False otherwise
 *
 *  @see Position_Component
 */
bool Camera_System::register_camera_entity(Entity* newEntity){
    if (newEntity->get_component(POSITION) ) {
        camera_ = newEntity;
        return true;
    }
    
    return false;
}

/** Updates the camera object's position based on the position of the entity object.
 *  The camera is positioned so the entity is always in the center unless the camera is clamped to the world bounds
 *
 */
void Camera_System::update(){
    int entityX = n8::get_position_component(entity_to_follow_)->get_position()->get_x();
    int entityY = n8::get_position_component(entity_to_follow_)->get_position()->get_y();
    int entW = n8::get_position_component(entity_to_follow_)->get_width();
    int entH = n8::get_position_component(entity_to_follow_)->get_height();
    int newX = entityX + .5*entW - n8::get_position_component(camera_)->get_width()/2;
    int newY = entityY + .5*entH - n8::get_position_component(camera_)->get_height()/2;
    
    if (newX < 0) {
        newX = 0;
    }
    if (newX > world_width_ -n8::get_position_component(camera_)->get_width()) {
        newX = world_width_ - n8::get_position_component(camera_)->get_width();
    }
    
    if (newY < 0) {
        newY = 0;
    }
    if (newY > world_height_ -n8::get_position_component(camera_)->get_height()) {
        newY = world_height_ -n8::get_position_component(camera_)->get_height();
    }
    
    n8::get_position_component(camera_)->get_position()->set_x(newX);
    n8::get_position_component(camera_)->get_position()->set_y(newY);
}


