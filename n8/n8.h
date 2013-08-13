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

//#include "Game_Manager.h"
#include "Game_Manager.h"
#include "Entity.h"
#include "Name_Component.h"
#include "Position_Component.h"
#include "Drawable_Component.h"
#include "Controllable_Coponent.h"
#include "Size_Component.h"
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
static const string SIZE =                  "SIZE";


// Static constants for system identifiers
static const string BASE_SYSTEM =           "BASE_SYSTEM";
static const string RENDER_SYSTEM =         "RENDER_SYSTEM";
static const string MOVEMENT_SYSTEM =       "MOVEMENT_SYSTEM";
static const string COLLISION_SYSTEM =      "COLLISION_SYSTEM";
static const string INTERACTION_SYSTEM =    "INTERACTION_SYSTEM";
static const string MESSAGE_SYSTEM =        "MESSAGE_SYSTEM";
static const string CAMERA_SYSTEM = 		"CAMERA_SYSTEM";

static const string PROJECTILE_SYSTEM =     "PROJECTILE_SYSTEM";


class n8{

private:
    static int nextid_; /** < Static counter to get available id values for created entities **/
public:
    
    n8();
    
    static int get_next_id();
    static Name_Component* get_name_component(Entity* entity);
    static Position_Component* get_position_component(Entity* entity);
    static Drawable_Component* get_drawable_component(Entity* entity);
    //static Size_Component* get_size_component(Entity* entity);
    
    static Render_System* get_render_system(Game_Manager* game);
    
    static void log_error(string tag,string msg);
    static void log_info(string tag, string msg);
    static void log_debug(string tag, string msg);

};

#endif 
