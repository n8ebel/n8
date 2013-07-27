#ifndef N8_H
#define N8_H

#include "cEntity.h"
#include "cName_Component.h"
#include "cPosition_Component.h"
#include <string>

//static const string COMPONENTS[] = {"NAME","DRAWABLE"};


class n8{

 private:

 public:
    static int nextID;
    
    n8();
    
    // Static constants for component identifiers
    static const string NAME;
    static const string DRAWABLE;
    static const string POSITION;
    static const string INTERACTABLE;
    
    // Static constants for system identifiers
    static const string RENDER_SYSTEM;
    static const string MOVEMENT_SYSTEM;
    static const string COLLISION_SYSTEM;
    static const string INTERACTION_SYSTEM;
    static const string MESSAGE_SYSTEM;
    
    
    static cEntity* create_user_entity(int id, string initName, int initX, int initY);
    static cName_Component* get_name_component(cEntity* entity);
    static cPosition_Component* get_position_component(cEntity* entity);

};

#endif 
