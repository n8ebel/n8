/*
 * Size_Component.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            8/6/13
 * Organization:    n8Tech
 *
*/

#include "Size_Component.h"
#include <iostream>

/** Default Destructor **/
Size_Component::~Size_Component(){
    
}

/** Constructor <p>
 *  Sets the height and width to be stored by the component 
 */
Size_Component::Size_Component(string id, int w, int h) : Component(id){
    width_ = w;
    height_ = h;
}