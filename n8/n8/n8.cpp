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
#include "constants.h"
#include <iostream>
#include <string>


using namespace std;


// Static counter for unique entity ID's
int n8::nextid_ = 0;

/* default constructor 
 * 
*/ 
n8::n8(){
    
}

int n8::get_next_id(){
    nextid_++;
    return nextid_;
}

/** get_name_component
 *
 *  entity- the entity from which to retrieve the component
 *
 *  Use-    Provides a static helper method for getting a component from an entity
 *          Returns a Name_Component* if the component exists, or NULL
 *
 */
Name_Component* n8:: get_name_component(Entity* entity){
    cout << entity->get_components().size() << endl;
    return (Name_Component*)entity->get_components()[NAME];
}

/** get_position_component
 *
 *  entity- the entity from which to retrieve the component
 *
 *  Use-    Provides a static helper method for getting a component from an entity
 *          Returns a Position_Component* if the component exists, or NULL
 *
 */
Position_Component* n8:: get_position_component(Entity* entity){
    return (Position_Component*)entity->get_components()[POSITION];
}

/** get_drawable_component
 *  Provides a static helper method for getting a position component from an entity
 *
 *  @param entity the entity from which to retrieve the component
 *  @return the stored Drawable_Component* or NULL
 */
Drawable_Component* n8:: get_drawable_component(Entity* entity){
    return (Drawable_Component*)entity->get_components()[DRAWABLE];
}

/** get_size_component
 *  Provides a static helper method for getting a size component from an entity
 *
 *  @param entity the entity from which to retrieve the component
 *  @return the stored Size_Component* or NULL
 */
Size_Component* n8:: get_size_component(Entity* entity){
    return (Size_Component*)entity->get_components()[SIZE];
}

void n8::log_error(string tag, string msg){
    cout << "(ERROR) " << tag << ": " << msg << endl;
}

void n8::log_info(string tag, string msg){
    cout << "(INFO) " << tag << ": " << msg << endl;
}

void n8::log_debug(string tag, string msg){
    if (DEBUG_MODE) {
        cout << "(DEBUG) " << tag << ": " << msg << endl;
    }
}

Render_System* n8::get_render_system(Game_Manager* game){
    if (game != NULL) {
        return ((Render_System*)game->get_system(RENDER_SYSTEM));
    }
    else{
        return NULL;
    }
}


