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

#include "Position_Component.h"


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
Position_Component::Position_Component(Point2D* newPosition, int w, int h) {
    m_id = new ID(COMPONENT_POSITION);
    position_ = newPosition;
    update_location(position_->GetX(), position_->GetY(), w,h);
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
Position_Component::Position_Component(int initX, int initY, int w, int h) {
    m_id = new ID(COMPONENT_POSITION);
    position_ = new Point2D(initX, initY);
    update_location(position_->GetX(), position_->GetY(), w,h);
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
	position_->SetX(x);
	position_->SetY(y);
	width_ = w;
	height_ = h;

	left_ = position_->GetX();
	top_ = position_->GetY();
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
    position_->AddX(xOffset);
    position_->AddY(yOffset);
    
    update_location(position_->GetX(), position_->GetY(), width_, height_);
}
