/*
 * n8.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

#include "n8.h"
#include "Game_Manager.h"
#include "State_Manager.h"
#include "Event_Manager.h"
#include "Input_Manager.h"

#include <iostream>
#include <string>
#include <sstream>


using namespace std;

/* Default Constructor
 * 
*/ 
n8::n8(){
    
}



bool n8::setup_n8(){
    if (SDL_Init( SDL_INIT_EVERYTHING ) == 0){
        return true;
    }
    else{
        return false;
    }
}


bool n8::shutdown_n8(){
    delete Input_Manager::getInstance();
    delete State_Manager::getInstance();
    delete Game_Manager::getInstance();
    delete Event_Manager::getInstance();
    
    return true;
}

/** A convienience method for getting a pointer to an entity's Name_Component
 *
 *  @param entity The entity to get the Name_Component from
 *  @return A pointer to the entity's Name_Component, or NULL if the entity doesn't contain that component
 *
 *  @see Name_Component
 *  @see Entity
 */
/*
Name_Component* n8:: get_name_component(Entity* entity){
    //return (Name_Component*)entity->get_components()[NAME];
    return static_cast<Name_Component*>(entity->get_component(NAME));
}
 */

/** A convienience method for getting a pointer to an entity's Position_Component
 *
 *  @param entity The entity to get the Position_Component from
 *  @return A pointer to the entity's Position_Component, or NULL if the entity doesn't contain that component
 *
 *  @see Position_Component
 *  @see Entity
 */
/*
Position_Component* n8:: get_position_component(Entity* entity){
    //return (Position_Component*)entity->get_components()[POSITION];
	return static_cast<Position_Component*>(entity->get_component(POSITION));
}
 */

/** A convienience method for getting a pointer to an entity's Drawable_Component
 *
 *  @param entity The entity to get the Drawable_Component from
 *  @return A pointer to the entity's Drawable_Component, or NULL if the entity doesn't contain that component
 *
 *  @see Drawable_Component
 *  @see Entity
 */
/*
Drawable_Component* n8:: get_drawable_component(Entity* entity){
    //return (Drawable_Component*)entity->get_components()[DRAWABLE];
	return static_cast<Drawable_Component*>(entity->get_component(DRAWABLE));
}
 */

/** A convienience method for getting a pointer to an entity's Size_Component
 *
 *  @param entity The entity to get the Size_Component from
 *  @return A pointer to the entity's Size_Component, or NULL if the entity doesn't contain that component
 *
 *  @see Size_Component
 *  @see Entity
 *//*
Size_Component* n8:: get_size_component(Entity* entity){
    return (Size_Component*)entity->get_components()[SIZE];
}*/


/** Used to get a pointer to a Game_Manager object's render system
 *
 *  @param game A pointer to a game manager
 *  @return A pointer to the game manager's render system, or NULL if the Game_Manager object doesn't have a registered render system.
 *
 *  @see Render_System
 *  @see Game_Manager
 *//*
Render_System* n8::get_render_system(Game_Manager* game){
    if (game != NULL) {
        return ((Render_System*)game->get_system(RENDER_SYSTEM));
    }
    else{
        return NULL;
    }
}
*/

