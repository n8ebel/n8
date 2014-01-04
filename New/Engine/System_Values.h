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

static const string GAME_MANAGER = "Game_Manager";
static const string STATE_MANAGER = "State_Manager";
static const string INPUT_MANAGER = "Input_Manager";
static const string EVENT_MANAGER = "Event_Manager";



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


#endif
