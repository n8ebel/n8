/*
 * Interaction_System.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            8/12/13
 * Organization:    n8Tech
 *
 */

#include <iostream>
#include <string>
#include <map>

#include "Interaction_System.h"
#include "n8.h"

using namespace std;

/** Default Destructor **/
Interaction_System::~Interaction_System() {
	// TODO Auto-generated destructor stub
}

/** Default Constructor **/
Interaction_System::Interaction_System(Game_Manager* gameManager) {
	requirements_[DRAWABLE] = 1;
    requirements_[POSITION] = 1;
    id_ = INTERACTION_SYSTEM;
    pick_interaction_function_ = NULL;
    game_ = gameManager;

}

/** Checks if two entities collide
 *
 * 	@param ent1 The first entity to check
 * 	@param ent2 The second entity to check
 * 	@return True if the two entities overlap, False otherwise
 *
 * 	@see Entity
 */
bool Interaction_System::do_collide(Entity* ent1, Entity* ent2){
	if(DEBUG_){
		Log::debug(id_ + ".do_collide", "Checking if Entity " + Numerical_Utilities::num_to_string(ent1->get_id()) + " and Entity " + Numerical_Utilities::num_to_string(ent2->get_id()) + " are colliding");
	}

    if (ent1->get_id() == SCREEN || ent2->get_id() == SCREEN) {
        return false;
    }
    else if (ent1->get_id() == CAMERA || ent2->get_id() == CAMERA){
        return false;
    }
    else if (ent1->get_id() == BACKGROUND || ent2->get_id() == BACKGROUND){
        return false;
    }
	else if( n8::get_position_component(ent1)->get_right() < n8::get_position_component(ent2)->get_left() ){
		return false;
	}
	else if( n8::get_position_component(ent1)->get_left() > n8::get_position_component(ent2)->get_right() ){
		return false;
	}
	else if( n8::get_position_component(ent1)->get_top() > n8::get_position_component(ent2)->get_bottom() ){
		return false;
	}
	else if( n8::get_position_component(ent1)->get_bottom() < n8::get_position_component(ent2)->get_top() ){
		return false;
	}
	else{
		if(DEBUG_){
			Log::debug(id_ + ".do_collide", "Collision Detected");
		}
        return true;
	}
    //cout << "not good" << endl;
    return false;
}

/** Calls the correct interaction function based on which two entities are interacting
 *
 *  @param ent1 The first entity that is interacting
 *  @param ent2 The second entity that is interacting
 */
void Interaction_System::pick_interaction(Entity* ent1, Entity* ent2){
	if(pick_interaction_function_ != NULL){
		pick_interaction_function_(this,ent1, ent2);
	}
	else{

	}
    
}

/** Performs some action involving two passed entities that interact.  This could involve
 *  moving entities so they no longer collide, destroying an entity, loading a dialog, etc.
 *  The action is defined within a function that must be registered with the system via
 *  function pointer.  Interaction functions must be registered with the system and must provide and identifier
 *  so the proper interaction function can be called.  Function pointers for interaction types
 *  are stored in registered_interactions_.
 *
 * 	@param interactionType
 * 	@param ent1 The first entity to operate on
 * 	@param ent2 The second entity to operate on
 *
 * 	@see Entity
 */
void Interaction_System::handle_interaction(string interactionType, Entity* ent1, Entity* ent2){
	if(DEBUG_){
		Log::debug(id_ + ".handle_interaction", "Handling interaction for Entity" + Numerical_Utilities::num_to_string(ent1->get_id()) + " and Entity " + Numerical_Utilities::num_to_string(ent2->get_id()));
	}
	map<string, interactionFunction>::iterator ii = registered_interactions_.find(interactionType);
	if(ii != registered_interactions_.end()){
		registered_interactions_[interactionType](game_, ent1, ent2);
	}
	else{
		if(DEBUG_){
			Log::error(id_ + ".handle_interaction", "Unable to call the desired interaction function");
		}
	}
}

/** Registers a function pointer to the system to perfrom some action when a particular type of interaction occurs.
 * 	The function pointer is passed with an identifier and stored in registered_interactions_ so they can be accessed
 * 	when needed.
 *
 * 	@param interactionType The identifier for a unique interaction type
 * 	@param func The function pointer to the desired action
 * 	@return True if the function did not already exist and was stored in registered_interactions_, False otherwise.
 */
bool Interaction_System::register_interaction(string interactionType, void (*func)(Game_Manager* game, Entity* ent1, Entity* ent2)){
	if(DEBUG_){
		Log::debug(id_ + ".register_interaction", "Registering interaction type: " + interactionType);
	}
	map<string, interactionFunction>::iterator ii = registered_interactions_.find(interactionType);
	if(ii == registered_interactions_.end()){
		registered_interactions_[interactionType] = func;
		if(DEBUG_){
			Log::debug(id_ + ".register_interaction", "Successfully registered interaction type: " + interactionType);
		}
		return true;
	}
	else{
		if(DEBUG_){
			Log::error(id_ + ".register_interaction", "Interaction type: " + interactionType + " already exists");
		}
		return false;
	}
}

/** Registers a function with the system that will control how/when registered interaction functions
 *  are used.
 *
 *  @param func The function pointer for the function to control which interaction functions are called
 */
void Interaction_System::register_pick_interaction_function(pickInteractionFunction func){
	pick_interaction_function_ = func;
}

void Interaction_System::update(){
	if (DEBUG_UPDATE_) {
		Log::debug(id_ + ".update", "");
	}

    map<int, Entity*>::iterator ii;
    map<int, Entity*>::iterator jj;
    for (ii = registered_entities_map_.begin(); ii != registered_entities_map_.end(); ii++) {
        jj = ii;
        advance(jj, 1);
        for (jj; jj != registered_entities_map_.end(); jj++) {
            if ( do_collide(ii->second, jj->second)) {
                pick_interaction(ii->second, jj->second);
            }
        }
    }
}
