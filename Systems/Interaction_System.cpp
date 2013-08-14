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
    /*
    cout << "do_collide: " << ent1->get_id() << " , " << ent2->get_id() << endl;
    cout << "left1: " << n8::get_position_component(ent1)->get_left() << endl;
    cout << "right1: " << n8::get_position_component(ent1)->get_right() << endl;
    cout << "top1: " << n8::get_position_component(ent1)->get_top() << endl;
    cout << "bottom1: " << n8::get_position_component(ent1)->get_bottom() << endl;
    
    cout << "left2: " << n8::get_position_component(ent2)->get_left() << endl;
    cout << "right3: " << n8::get_position_component(ent2)->get_right() << endl;
    cout << "top3: " << n8::get_position_component(ent2)->get_top() << endl;
    cout << "bottom3: " << n8::get_position_component(ent2)->get_bottom() << endl;
     */
    
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
    if( ent1->get_type() == PROJECTILE_TYPE || ent2->get_type() == PROJECTILE_TYPE ){
    	handle_interaction(PROJECTILE_INTERACTION, ent1, ent2);
    }
    else{
    	handle_interaction(GENERIC_INTERACTION, ent1, ent2);
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
	registered_interactions_[interactionType](game_, ent1, ent2);
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
	map<string, interactionFunction>::iterator ii = registered_interactions_.find(interactionType);
	if(ii == registered_interactions_.end()){
		registered_interactions_[interactionType] = func;
		return true;
	}
	else{
		return false;
	}
}

void Interaction_System::update(){
    //cout << "updating " << endl;
    for (int i = 0; i < registered_entities_.size(); i++) {
        for (int j = i+1; j < registered_entities_.size(); j++) {
            if ( do_collide(registered_entities_[i], registered_entities_[j])) {
                pick_interaction(registered_entities_[i], registered_entities_[j]);
            }
        }
    }
}
