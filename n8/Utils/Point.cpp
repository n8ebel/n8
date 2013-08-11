/*
 * Point.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

#include <iostream>
#include "Point.h"

Point::~Point(){
    
}

/** Constructor <p>
 *  Sets the initial position of the point
 */
Point::Point(int initX, int initY){
    x_ = initX;
    y_ = initY;
}

