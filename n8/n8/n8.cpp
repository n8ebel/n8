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


/*
cEntity* n8::create_user_entity(int id, string initName, int initX, int initY){
    
    cEntity* foo = new cEntity(id);
    cName_Component* name = new cName_Component(NAME, initName);
    cPosition_Component* position = new cPosition_Component(POSITION, initX, initY);
    
    foo->add_component(name);
    foo->add_component(position);
    
    return foo;
    
}
*/
cName_Component* n8:: get_name_component(cEntity* entity){
    cout << entity->get_components().size() << endl;
    return (cName_Component*)entity->get_components()[NAME];
}

cPosition_Component* n8:: get_position_component(cEntity* entity){
    return (cPosition_Component*)entity->get_components()[POSITION];
}

void n8::log_error(string msg){
    cout << "(ERROR) " << msg << endl;
}

void n8::log_info(string msg){
    cout << "(INFO) " << msg << endl;
}


