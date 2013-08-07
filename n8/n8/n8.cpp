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
int n8::nextID = 0;

/* default constructor 
 * 
*/ 
n8::n8(){
    
}

int n8::get_next_id(){
    nextID++;
    return nextID;
}

/** get_name_component
 *
 *  entity- the entity from which to retrieve the component
 *
 *  Use-    Provides a static helper method for getting a component from an entity
 *          Returns a cName_Component* if the component exists, or NULL
 *
 */
cName_Component* n8:: get_name_component(cEntity* entity){
    cout << entity->get_components().size() << endl;
    return (cName_Component*)entity->get_components()[NAME];
}

/** get_position_component
 *
 *  entity- the entity from which to retrieve the component
 *
 *  Use-    Provides a static helper method for getting a component from an entity
 *          Returns a cPosition_Component* if the component exists, or NULL
 *
 */
cPosition_Component* n8:: get_position_component(cEntity* entity){
    return (cPosition_Component*)entity->get_components()[POSITION];
}

/** get_drawable_component
 *  Provides a static helper method for getting a position component from an entity
 *
 *  @param entity the entity from which to retrieve the component
 *  @return the stored cDrawable_Component* or NULL
 */
cDrawable_Component* n8:: get_drawable_component(cEntity* entity){
    return (cDrawable_Component*)entity->get_components()[DRAWABLE];
}

/** get_size_component
 *  Provides a static helper method for getting a size component from an entity
 *
 *  @param entity the entity from which to retrieve the component
 *  @return the stored cSize_Component* or NULL
 */
cSize_Component* n8:: get_size_component(cEntity* entity){
    return (cSize_Component*)entity->get_components()[SIZE];
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


