/*
* Movement_Component.h
* n8
*
* Author:          Nate Ebel
* Date:            8/13/13
* Organization:    n8Tech
*
*/
#ifndef MOVEMENTCOMPONENT_H
#define MOVEMENTCOMPONENT_H

#include <string>

#include "Component.h"

class Movement_Component: public Component {
public:
	Movement_Component(string newID, double x, double y, double mag);
	virtual ~Movement_Component();

	/** Gets the amount to move in the x direction
	 *
	 *  @param The integer amount to move in the x direction
	 */
	int get_x_offset() { return x_direction_ * magnitude_; }

	/** Gets the amount to move in the y direction
	 *
	 *  @param The integer amount to move in the y direction
	 */
	int get_y_offset() { return y_direction_ * magnitude_; }

private:
	double x_direction_;
	double y_direction_;
	double magnitude_;
};

#endif /* MOVEMENTCOMPONENT_H_ */
