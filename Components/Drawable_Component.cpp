/*
 * Drawable_Component.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/29/13
 * Organization:    n8Tech
 *
*/

#include "Drawable_Component.h"
#include "Sprite.h"

#include <iostream>


/** Default Constructor
 *
 */
Drawable_Component::~Drawable_Component(){
    //delete sprite_;
}

/** Constructor
 *
 *  @param newID The identifier of the component
 *  @param newSprite The sprite to use to draw with
 */
Drawable_Component::Drawable_Component(string newID, Sprite* newSprite) : Component(newID){
    sprite_ = newSprite;
}
