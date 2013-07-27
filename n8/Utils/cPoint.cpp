//
//  cPoint.cpp
//  SDL_Test
//
//  Created by Nate Ebel on 7/22/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "cPoint.h"

cPoint::~cPoint(){
    
}

cPoint::cPoint(){
    
}

cPoint::cPoint(int initX, int initY){
    x = initX;
    y = initY;
}

int cPoint::get_x(){
    return x;
}

int cPoint::get_y(){
    return y;
}

void cPoint::add_x(int xOffset){
    x += xOffset;
}

void cPoint::add_y(int yOffset){
    y += yOffset;
}

void cPoint::set_x(int newX){
    x = newX;
}

void cPoint::set_y(int newY){
    y = newY;
}