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


Size_Component::~Size_Component(){
    
}

Size_Component::Size_Component(){
    width_ = 0;
    height_ = 0;
}

Size_Component::Size_Component(string id, int w, int h) : Component(id){
    width_ = w;
    height_ = h;
}


int Size_Component::get_width(){
    return width_;
}

int Size_Component::get_height(){
    return height_;
}