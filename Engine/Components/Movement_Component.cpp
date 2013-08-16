/*
 * Movement_Component.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            8/13/13
 * Organization:    n8Tech
 *
 */

#include "Movement_Component.h"

/** Constructor
 *
 *  @param newID The identifier of the component
 *  @param x The amount to move in the x direction
 *  @param y The amount to move in the y direction
 *  @param mag The magnitude of the movement.  The magnitude is applied to the x and y values to get the overal movement
 */
Movement_Component::Movement_Component(string newID, double x, double y, double mag) : Component(newID){
	x_direction_ = x;
	y_direction_ = y;
	magnitude_ = mag;

}

Movement_Component::~Movement_Component() {
	// TODO Auto-generated destructor stub
}

