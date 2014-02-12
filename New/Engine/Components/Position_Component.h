/*
 * Position_Component.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

#ifndef Position_Component_h
#define Position_Component_h

#include <string>

#include "Component.h"
#include "Point2D.h"

using namespace std;

/** Class that stores positonal information of an entity.  X and Y coordinates along
 *  with the coordinates of boudning box edges are stored.  The positon data can then
 *  be used for drawing, collison, and interaction operations.
 */
class Position_Component : public Component {
    
public:
    ~Position_Component();
    Position_Component(Point2D* newPosition, int w, int h);
    Position_Component(int initX, int initY, int w, int h);
    
    void update_location(int x, int y, int w, int h);

    /** Used to get the coordinates stored by the component.  These coordinates are used to track the location of entities.
     *
     *  @return The point object stored by the component
     *
     *  @see Component
     *  @see Point2D
     */
    Point2D* get_position() { return position_; }
    
    /**  Used to get the x coordinate of the component
     *
     *  @return The x coordinate stored by the position_
     */
    int get_x() { return position_->GetX(); }
    
    /**  Used to get the y coordinate of the component
     *
     *  @return The y coordinate stored by the position_
     */
    int get_y() { return position_->GetY(); }
    
    /** Used to get the coordinate of the left side of the entity
     *
     * 	@return The x coordinate of the left side of the entity
     */
    int get_left() { return left_; }

    /** Used to get the coordinate of the right side of the entity
     *
     * 	@return The x coordinate of the right side of the entity
     */
    int get_right() { return right_; }

    /** Used to get the coordinate of the top side of the entity
     *
     * 	@return The y coordinate of the top side of the entity
     */
    int get_top() { return top_; }

    /** Used to get the coordinate of the botoom side of the entity
     *
     * 	@return The y coordinate of the bottom side of the entity
     */
    int get_bottom() { return bottom_; }

    /** Used to get the width stored by the component
     *
     *  @return The width of the component
     */
    int get_width() { return width_; }

    /** Used to get the height stored by the component
     *
     *  @return The height of the component
     */
    int get_height() { return height_; }

    void update_position(int xOffset, int yOffset);
    
private:
    Point2D* position_;   /** < Stores the x&y coordinates of the component */
    int left_;
    int right_;
    int top_;
    int bottom_;
    int width_;
    int height_;
};

#endif
