/*
 * Position_Component.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

#include <iostream>
#include "Component.h"
#include "Position_Component.h"
#include "Point.h"

/** Default Destructor **/
Position_Component::~Position_Component(){
    delete position_;
}

/** Constructor <p>
 *  Creates a new object using an ID and an existing Point object
 *
 *  @param newID The identifier for the component
 *  @param newPosition The point to use to store the components coordinates
 */
Position_Component::Position_Component(string newID, Point* newPosition) : Component(newID){
    position_ = newPosition;
}

/** Constructor <p>
 *  Creates a new object using an ID and x and y coordinates.
 *  The passed coordinates are used to create a Point object that is stored
 *
 *  @param newID The identifier for the component
 *  @param initX The x position of the component
 *  @param initY The y position of the component
 */
Position_Component::Position_Component(string newID, int initX, int initY) : Component(newID){
    position_ = new Point(initX, initY);
}

/** Updates the position stored by the component
 *
 *  @param xOffset The amount to add to the x coordinate
 *  @param yOffset The amount to add to the y coordinate
 */
void Position_Component::update_position(int xOffset, int yOffset){
    position_->add_x(xOffset);
    position_->add_y(yOffset);
}
