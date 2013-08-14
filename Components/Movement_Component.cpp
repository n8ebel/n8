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
#include "Component.h"

Movement_Component::Movement_Component(string newID, double x, double y, double mag) : Component(newID){
	x_direction_ = x;
	y_direction_ = y;
	magnitude_ = mag;

}

Movement_Component::~Movement_Component() {
	// TODO Auto-generated destructor stub
}

