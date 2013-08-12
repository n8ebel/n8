/*
 * Interaction_System.cpp
 *
 *  Created on: Aug 12, 2013
 *      Author: nath7313
 */

#include <string>
#include <map>

#include "Interaction_System.h"
#include "n8.h"

/** Default Destructor **/
Interaction_System::~Interaction_System() {
	// TODO Auto-generated destructor stub
}

/** Default Constructor **/
Interaction_System::Interaction_System() {
	// TODO Auto-generated constructor stub

}

/** Checks if two entities collide
 *
 * 	@param ent1 The first entity to check
 * 	@param ent2 The second entity to check
 * 	@return True if the two entities overlap, False otherwise
 *
 * 	@see Entity
 */
bool Interaction_System::do_collide(Entity ent1, Entity ent2){

    return false;
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
void Interaction_System::handle_interaction(string interactionType, Entity ent1, Entity ent2){

}

/** Registers a function pointer to the system to perfrom some action when a particular type of interaction occurs.
 * 	The function pointer is passed with an identifier and stored in registered_interactions_ so they can be accessed
 * 	when needed.
 *
 * 	@param interactionType The identifier for a unique interaction type
 * 	@param func The function pointer to the desired action
 * 	@return True if the function did not already exist and was stored in registered_interactions_, False otherwise.
 */
bool Interaction_System::register_interaction(string interactionType, void (*func)(Game_Manager game, Entity ent1, Entity ent2)){

    return false;
}

void Interaction_System::update(){

}
