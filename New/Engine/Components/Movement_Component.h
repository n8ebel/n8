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
	Movement_Component(double x, double y, double mag, bool worldBound);
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
    
    /** Indicates whether an entity can leave the world bounds or not
     *
     *  @return True if the entity can move outside the world bounds, False otherwise
     */
    bool is_world_bound() { return world_bound_; }

private:
	double x_direction_;
	double y_direction_;
	double magnitude_;
    bool world_bound_;
};

#endif /* MOVEMENTCOMPONENT_H_ */
