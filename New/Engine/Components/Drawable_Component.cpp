/*
 * Drawable_Component.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/29/13
 * Organization:    n8Tech
 *
*/

#include <iostream>

#include "Drawable_Component.h"

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
Drawable_Component::Drawable_Component(Sprite* newSprite) {
    m_id = new ID(COMPONENT_DRAWABLE);
    sprite_ = newSprite;
}
