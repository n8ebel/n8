/*
 * Point2D.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

#include "Point2D.h"

Point2D::~Point2D(){
    
}

/** Constructor <p>
 *  Sets the initial position of the point
 */
Point2D::Point2D(int initX, int initY){
    x_ = initX;
    y_ = initY;
}

