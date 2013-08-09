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

/** default constructor
 *
 */
Drawable_Component::Drawable_Component(){
    sprite_ = NULL;
}

/** default destructor
 *
 */
Drawable_Component::~Drawable_Component(){
    
}

/** additional constructor that will be used most often
 *
 */
Drawable_Component::Drawable_Component(string newID, Sprite* newSprite) : Component(newID){
    sprite_ = newSprite;
}


/** get_image
 *
 *  Use- returns the actual SDL_surface stored by the sprite object
 *
 */
SDL_Surface* Drawable_Component::get_image(){
    return sprite_->get_image();
}

/** get_sprite
 *
 *  Use-    returns the component's sprite
 *
 */
Sprite* Drawable_Component::get_sprite(){
    return sprite_;
}

/** set_sprite
 *
 *  newSprite-  the new sprite for the component
 *
 *  Use-    allows the user to change the sprite for a drawable component
 *
 */
Sprite* Drawable_Component::set_sprite(Sprite* newSprite){
    sprite_ = newSprite;
    return sprite_;
}