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

Point::Point(){
    
}

Point::Point(int initX, int initY){
    x_ = initX;
    y_ = initY;
}

int Point::get_x(){
    return x_;
}

int Point::get_y(){
    return y_;
}

void Point::add_x(int xOffset){
    x_ += xOffset;
}

void Point::add_y(int yOffset){
    y_ += yOffset;
}

void Point::set_x(int newX){
    x_ = newX;
}

void Point::set_y(int newY){
    y_ = newY;
}