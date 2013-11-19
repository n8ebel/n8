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

/** Default Destructor **/
Camera_System::~Camera_System(){
    
}

/** Default Constructor <p>
 *  Initializes entity_to_follow_ and camera_ to NULL
 */
Camera_System::Camera_System(Game_Manager* gameManager){
    entity_to_follow_ = NULL;
    camera_ = NULL;
    game_ = gameManager;
    world_width_ = 1;
    world_height_ =1;
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
	if (DEBUG_) {
		Log::debug(id_ + ".register_entity_to_follow", "Registering Entity " + Numerical_Utilities::num_to_string(newEntity->get_id()) + " as entity for the camera to follow");
	}

    if (newEntity->get_component(POSITION) != NULL && newEntity->get_component(DRAWABLE) != NULL) {
        entity_to_follow_ = newEntity;
        return true;
    }
    
    if (DEBUG_) {
    	Log::error(id_ + ".register_entity_to_follow", "Failed to register the entity because it didn't have a Position and a Drawable component");
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
	if (DEBUG_) {
		Log::debug(id_ + ".register_camera_entity", "Registering Entity " + Numerical_Utilities::num_to_string(newEntity->get_id()) + " as camera");
	}

    if (newEntity->get_component(POSITION) != NULL ) {
        camera_ = newEntity;
        return true;
    }
    
    if (DEBUG_) {
    	Log::error(id_ + ".register_camera_entity", "Failed to register the camera because no Position_Component could be found");
	}
    return false;
}

/** Updates the camera object's position based on the position of the entity object.
 *  The camera is positioned so the entity is always in the center unless the camera is clamped to the world bounds
 *
 */
void Camera_System::update(){
	if (DEBUG_UPDATE_) {
		Log::debug(id_ + ".update", "");
	}

    if (entity_to_follow_ != NULL && camera_ != NULL) {
        
        Position_Component* entityPosition = n8::get_position_component(entity_to_follow_);
        Position_Component* cameraPosition = n8::get_position_component(camera_);
        
        if (entityPosition != NULL && cameraPosition != NULL) {
            
            int entityX = entityPosition->get_position()->get_x();
            int entityY = entityPosition->get_position()->get_y();
            int entW = entityPosition->get_width();
            int entH = entityPosition->get_height();
            int newX = entityX + .5*entW - cameraPosition->get_width()/2;
            int newY = entityY + .5*entH - cameraPosition->get_height()/2;
            
            if (newX < 0) {
                newX = 0;
            }
            if (newX > world_width_ - cameraPosition->get_width()) {
                newX = world_width_ - cameraPosition->get_width();
            }
            
            if (newY < 0) {
                newY = 0;
            }
            if (newY > world_height_ - cameraPosition->get_height()) {
                newY = world_height_ - cameraPosition->get_height();
            }
            
            cameraPosition->get_position()->set_x(newX);
            cameraPosition->get_position()->set_y(newY);
        }
    
        
    }
}


