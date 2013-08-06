/*
 * n8.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */  

#ifndef N8_H
#define N8_H

//#include "cGame_Manager.h"
#include "cEntity.h"
#include "cName_Component.h"
#include "cPosition_Component.h"
#include "cDrawable_Component.h"
#include "cControllable_Coponent.h"
#include <string>


static const bool DEBUG_MODE = false;
static const bool DEBUG_UPDATE = false;

const int SCREEN = -1;
const int CAMERA = -2;


// Static constants for component identifiers
static const string NAME =                  "NAME";
static const string DRAWABLE =              "DRAWABLE";
static const string POSITION =              "POSITION";
static const string INTERACTABLE =          "INTERACTABLE";
static const string CONTROLLABLE =          "CONTROLLABLE";


// Static constants for system identifiers
static const string BASE_SYSTEM =           "BASE_SYSTEM";
static const string RENDER_SYSTEM =         "RENDER_SYSTEM";
static const string MOVEMENT_SYSTEM =       "MOVEMENT_SYSTEM";
static const string COLLISION_SYSTEM =      "COLLISION_SYSTEM";
static const string INTERACTION_SYSTEM =    "INTERACTION_SYSTEM";
static const string MESSAGE_SYSTEM =        "MESSAGE_SYSTEM";
static const string CAMERA_SYSTEM = "CAMERA_SYSTEM";


class n8{

private:
    static int nextID;
public:
    
    n8();
    
    static int get_next_id();
        
        
   // static cEntity* create_user_entity(int id, string initName, int initX, int initY);
    static cComponent* get_component(cEntity* entity, string component);
    static cName_Component* get_name_component(cEntity* entity);
    static cPosition_Component* get_position_component(cEntity* entity);
    static cDrawable_Component* get_drawable_component(cEntity* entity);
    
    static void log_error(string tag,string msg);
    static void log_info(string tag, string msg);
    static void log_debug(string tag, string msg);

};

#endif 
