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
 *  @param w The width of the component
 *  @param h The height of the component
 */
Position_Component::Position_Component(string newID, Point* newPosition, int w, int h) : Component(newID){
    position_ = newPosition;
    update_location(position_->get_x(), position_->get_y(), w,h);
}

/** Constructor <p>
 *  Creates a new object using an ID and x and y coordinates.
 *  The passed coordinates are used to create a Point object that is stored
 *
 *  @param newID The identifier for the component
 *  @param initX The x position of the component
 *  @param initY The y position of the component
 *  @param w The width of the component
 *  @param h The height of the component
 */
Position_Component::Position_Component(string newID, int initX, int initY, int w, int h) : Component(newID){
    position_ = new Point(initX, initY);
    update_location(position_->get_x(), position_->get_y(), w,h);
}

/** Used to update the position data stored by the component.  It could be used when a sprite changes
*  and the image size causes positions to change.  It could also be used if the level changes and the
*  entity's location greatly changes.
*
*  @param x The new x coordinate
*  @param y The new y coordinate
*  @param w The new width of the component
*  @param h The new height of the component
*/
void Position_Component::update_location(int x, int y, int w, int h){
	position_->set_x(x);
	position_->set_y(y);
	width_ = w;
	height_ = h;

	left_ = position_->get_x();
	top_ = position_->get_y();
	right_ = left_ + width_;
	bottom_ = top_ + height_;
}
/** Updates the position stored by the component by adding an x and/or y offset to the current
 *  position coordinates.
 *
 *  @param xOffset The amount to add to the x coordinate
 *  @param yOffset The amount to add to the y coordinate
 */
void Position_Component::update_position(int xOffset, int yOffset){
    position_->add_x(xOffset);
    position_->add_y(yOffset);
    
    update_location(position_->get_x(), position_->get_y(), width_, height_);
}
