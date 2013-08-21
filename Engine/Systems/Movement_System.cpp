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
    requirements_[MOVEMENT] = 1;
    id_ = MOVEMENT_SYSTEM;
    game_ = gameManager;
    user_entity_ = NULL;
    world_width_= 1;
    world_height_=1;
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
    
    if ( (curX+xOffset) >= 0 && (curX + width+xOffset) <= world_width_){
        
        if( (curY+yOffset) >= 0 && (curY + height+yOffset) <= world_height_){
            
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

/** Registers a user controlled entity with the movement system so it can be controlled by the keyboard
 *
 *  @param userEntity The entity that the user will be controlling with the keyboard
 */
void Movement_System::register_user_entity(Entity* userEntity){
	if(DEBUG_){
		Log::debug(id_ + ".register_user_entity", "Entity: " + Numerical_Utilities::num_to_string(userEntity->get_id()));
	}
    user_entity_ = userEntity;
}

/** Updates the position of all registered entities.  Using the speed and direction stored in the
 *  Movement_Component, each entity's position is updated.
 */
void Movement_System::update(){
	if(DEBUG_UPDATE_){
		Log::debug(id_ + ".update", "");
	}
    map<int, Entity*>::iterator ii;
    for (ii = registered_entities_map_.begin(); ii != registered_entities_map_.end(); ii++) {
		if (ii->second->get_component(MOVEMENT) != NULL){
			Movement_Component* moveComp = static_cast<Movement_Component*>(ii->second->get_component(MOVEMENT));
			if( inside_world_bounds(ii->second, moveComp->get_x_offset(), moveComp->get_y_offset())){
				static_cast<Position_Component*>(ii->second->get_component(POSITION))->update_position(moveComp->get_x_offset(), moveComp->get_y_offset());
			}
            else{
                if( moveComp->is_world_bound()){
                    
                }
                else{
                    if(DEBUG_UPDATE_){
                        Log::debug(id_ + ".update", "Entity " + Numerical_Utilities::num_to_string(ii->second->get_id()) + " is outside the world as is being removed");
                    }
                    
                    game_->flag_to_remove_entity(ii->second);

                }
            }
            
		}
	}
}

/** Moves the registered entity by the specified offsets
 *
 * 	@param x The horizontal amount to move the registered entity
 * 	@param y The vertical amount to move the registered entity
 */
void Movement_System::move(int x, int y){
	if(DEBUG_){
		Log::debug(id_ + ".move", "");
	}
	if( inside_world_bounds(user_entity_, x, y)){
		if(DEBUG_){
			Log::debug(id_ + ".move", "Updating the position of the user entity");
		}
		((Position_Component*)user_entity_->get_component(POSITION))->update_position(x, y);

	}
}
void Movement_System::right(){
    if( inside_world_bounds(user_entity_, 5, 0)){
        ((Position_Component*)user_entity_->get_component(POSITION))->update_position(5, 0);
        
    }
}
void Movement_System::down(){
    if( inside_world_bounds(user_entity_, 0, 5)){
        ((Position_Component*)user_entity_->get_component(POSITION))->update_position(0, 5);
        
    }
}
void Movement_System::left(){
    if( inside_world_bounds(user_entity_, -5, 0)){
        ((Position_Component*)user_entity_->get_component(POSITION))->update_position(-5, 0);
        
    }
}
void Movement_System::up(){
    if( inside_world_bounds(user_entity_, 0, -5)){
        ((Position_Component*)user_entity_->get_component(POSITION))->update_position(0, -5);
        
    }
}
