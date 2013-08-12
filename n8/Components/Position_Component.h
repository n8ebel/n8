/*
 * Position_Component.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

#ifndef SDL_Test_Position_Component_h
#define SDL_Test_Position_Component_h

#include "Point.h"

using namespace std;

class Position_Component : public Component {
private:
    Point* position_;   /** < Stores the x&y coordinates of the component */
    
public:
    ~Position_Component();
    Position_Component(string newID, Point* newPosition);
    Position_Component(string newID, int initX, int initY);
    
    /** Used to get the coordinates stored by the component.  These coordinates are used to track the location of entities.
     *
     *  @return The point object stored by the component
     *
     *  @see Component
     *  @see Point
     */
    Point* get_position() { return position_; }
    
    /**  Used to get the x coordinate of the component
     *
     *  @return The x coordinate stored by the position_
     */
    int get_x() { return position_->get_x(); }
    
    /**  Used to get the y coordinate of the component
     *
     *  @return The y coordinate stored by the position_
     */
    int get_y() { return position_->get_y(); }
    
    void update_position(int xOffset, int yOffset);
};

#endif
