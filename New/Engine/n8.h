/*
 * Sprite_Manager.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */  

#ifndef N8_H
#define N8_H


#include "SDL/SDL.h"

#include "Input_Manager.h"
#include "State_Manager.h"
#include "Game_Manager.h"

#include "Menu_State.h"
#include "Game_State.h"
/*
//#include "Game_Manager.h"
#include "Game_Manager.h"
#include "Entity.h"
#include "Name_Component.h"
#include "Position_Component.h"
#include "Drawable_Component.h"
#include "Controllable_Coponent.h"
#include "Size_Component.h"
#include "Movement_Component.h"
#include "Color_Component.h"
#include <string>
 */


const int SCREEN = -1;
const int CAMERA = -2;
const int BACKGROUND = -3;

static const string GAME_MANAGER = "Game_Manager";
static const string STATE_MANAGER = "State_Manager";
static const string INPUT_MANAGER = "Input_Manager";


// Static constants for component identifiers
static const string NAME =                  "NAME";
static const string DRAWABLE =              "DRAWABLE";
static const string POSITION =              "POSITION";
static const string INTERACTABLE =          "INTERACTABLE";
static const string CONTROLLABLE =          "CONTROLLABLE";
static const string SIZE =                  "SIZE";
static const string MOVEMENT =				"MOVEMENT";
static const string COLOR =                 "COLOR";


// Static constants for system identifiers
static const string BASE_SYSTEM =           "BASE_SYSTEM";
static const string RENDER_SYSTEM =         "RENDER_SYSTEM";
static const string MOVEMENT_SYSTEM =       "MOVEMENT_SYSTEM";
static const string COLLISION_SYSTEM =      "COLLISION_SYSTEM";
static const string INTERACTION_SYSTEM =    "INTERACTION_SYSTEM";
static const string MESSAGE_SYSTEM =        "MESSAGE_SYSTEM";
static const string CAMERA_SYSTEM = 		"CAMERA_SYSTEM";

static const string PROJECTILE_INTERACTION =     "PROJECTILE_INTERACTION";
static const string GENERIC_INTERACTION =     	 "GENERIC_INTERACTION";

// Static entity types
static const string USER_TYPE =					"USER";
static const string ENEMY_TYPE =				"ENEMY";
static const string PROJECTILE_TYPE =			"PROJECTILE";
static const string SCREEN_TYPE =				"SCREEN";
static const string CAMERA_TYPE =				"CAMERA";
static const string BACKGROUND_TYPE =			"BACKGROUND";


class n8{

private:
    static int nextid_; /** < Static counter to get available id values for created entities **/
public:
    
    n8();
    
    static int get_next_id();
    static bool setup_n8();
    static bool shutdown_n8();

    /*
    static Name_Component* get_name_component(Entity* entity);
    static Position_Component* get_position_component(Entity* entity);
    static Drawable_Component* get_drawable_component(Entity* entity);

    static Size_Component* get_size_component(Entity* entity);
    static Render_System* get_render_system(Game_Manager* game);
     */
};

#endif 
