/*
 * constants.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/28/13
 * Organization:    n8Tech
 *
 */

#ifndef n8_constants_h
#define n8_constants_h

#include <iostream>
#include <string>

using namespace std;

const int SCREEN = -1;


// Static constants for component identifiers
static const string NAME =                  "NAME";
static const string DRAWABLE =              "DRAWABLE";
static const string POSITION =              "POSITION";
static const string INTERACTABLE =          "INTERACTABLE";


// Static constants for system identifiers
static const string BASE_SYSTEM =           "BASE_SYSTEM";
static const string RENDER_SYSTEM =         "RENDER_SYSTEM";
static const string MOVEMENT_SYSTEM =       "MOVEMENT_SYSTEM";
static const string COLLISION_SYSTEM =      "COLLISION_SYSTEM";
static const string INTERACTION_SYSTEM =    "INTERACTION_SYSTEM";
static const string MESSAGE_SYSTEM =        "MESSAGE_SYSTEM";

#endif
