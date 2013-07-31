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

cDrawable_Component::cDrawable_Component(){
    sprite = NULL;
}

cDrawable_Component::~cDrawable_Component(){
    
}

cDrawable_Component::cDrawable_Component(string newID, cSprite* newSprite) : cComponent(newID){
    sprite = newSprite;
}

cSprite* cDrawable_Component::get_sprite(){
    return sprite;
}

cSprite* cDrawable_Component::set_sprite(){
    
}