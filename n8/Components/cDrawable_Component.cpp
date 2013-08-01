/*
 * cDrawable_Component.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/29/13
 * Organization:    n8Tech
 *
*/

#include "cDrawable_Component.h"
#include "cSprite.h"

#include <iostream>

/** default constructor
 *
 */
cDrawable_Component::cDrawable_Component(){
    sprite = NULL;
}

/** default destructor
 *
 */
cDrawable_Component::~cDrawable_Component(){
    
}

/** additional constructor that will be used most often
 *
 */
cDrawable_Component::cDrawable_Component(string newID, cSprite* newSprite) : cComponent(newID){
    sprite = newSprite;
}

/** get_sprite
 *
 *  Use-    returns the component's sprite
 *
 */
cSprite* cDrawable_Component::get_sprite(){
    return sprite;
}

/** set_sprite
 *
 *  newSprite-  the new sprite for the component
 *
 *  Use-    allows the user to change the sprite for a drawable component
 *
 */
cSprite* cDrawable_Component::set_sprite(cSprite* newSprite){
    sprite = newSprite;
}