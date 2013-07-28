/*
 * cPoint.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

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