/*
 * cSize_Component.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            8/6/13
 * Organization:    n8Tech
 *
*/

#include "cSize_Component.h"
#include <iostream>


cSize_Component::~cSize_Component(){
    
}

cSize_Component::cSize_Component(){
    width = 0;
    height = 0;
}

cSize_Component::cSize_Component(string id, int w, int h) : cComponent(id){
    width = w;
    height = h;
}


int cSize_Component::get_width(){
    return width;
}

int cSize_Component::get_height(){
    return height;
}