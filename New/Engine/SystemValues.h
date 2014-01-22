/*
 * System_Values.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            1/3/14
 * Organization:    n8Tech
 *
 */

#ifndef SYSTEM_VALUES_H
#define SYSTEM_VALUES_H

#include <iostream>
#include <string>

using namespace std;


const int SCREEN = -1;
const int CAMERA = -2;
const int BACKGROUND = -3;

static const bool DEBUGGING = true;

static const string GAME_MANAGER = "Game Manager";
static const string STATE_MANAGER = "State Manager";
static const string INPUT_MANAGER = "Input Manager";
static const string EVENT_MANAGER = "Event Manager";
static const string RESOURCE_MANAGER = "Resource Manager";
static const string SYSTEM_MANAGER = "System Manager";
static const string SINGLETON = "Singleton";



// Static constants for component identifiers
/*
static const int NAME =                  0;
static const int DRAWABLE =              1;
static const int POSITION =              2;
static const int INTERACTABLE =          3;
static const int CONTROLLABLE =          4;
static const int SIZE =                  5;
static const int MOVEMENT =              6;
static const int COLOR =                 7;
*/
enum COMPONENT {COMPONENT_INVALID_FIRST,
                COMPONENT_BASE,
                COMPONENT_NAME,
                COMPONENT_DRAWABLE,
                COMPONENT_POSITION,
                COMPONENT_INTERACTABLE,
                COMPONENT_CONTROLLABLE,
                COMPONENT_SIZE,
                COMPONENT_MOVEMENT,
                COMPONENT_COLOR,
                COMPONENT_INVALID_SECOND};

static const string COMPONENT_IDS[] = { "INVALID FIRST",
                                        "BASE",
                                        "NAME",
                                        "DRAWABLE",
                                        "POSITION",
                                        "INTERACTABLE",
                                        "CONTROLLABLE",
                                        "SIZE",
                                        "MOVEMENT",
                                        "COLOR",
                                        "INVALID LAST"};

// Static constants for system identifiers
static const int BASE_SYSTEM =           0;
static const int RENDER_SYSTEM =         1;
static const int MOVEMENT_SYSTEM =       2;
static const int COLLISION_SYSTEM =      3;
static const int INTERACTION_SYSTEM =    4;
static const int MESSAGE_SYSTEM =        5;
static const int CAMERA_SYSTEM = 		6;

static const string SYSTEM_IDS[] = {"BASE SYSTEM",
                                    "RENDER SYSTEM",
                                    "MOVEMENT_SYSTEM",
                                    "COLLISION SYSTEM",
                                    "INTERACTION SYSTEM",
                                    "MESSAGE SYSTEM",
                                    "CAMERA SYSTEM"};

static const string PROJECTILE_INTERACTION =     "PROJECTILE_INTERACTION";
static const string GENERIC_INTERACTION =     	 "GENERIC_INTERACTION";

// Static entity types
static const string ENTITY =					"ENTITY";
static const string USER_TYPE =					"USER";
static const string ENEMY_TYPE =				"ENEMY";
static const string PROJECTILE_TYPE =			"PROJECTILE";
static const string SCREEN_TYPE =				"SCREEN";
static const string CAMERA_TYPE =				"CAMERA";
static const string BACKGROUND_TYPE =			"BACKGROUND";


#endif
