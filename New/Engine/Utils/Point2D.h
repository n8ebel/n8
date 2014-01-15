/*
 * Point2D.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

#ifndef POINT2D_H
#define POINT2D_H

/** Class to store an x and y coordinate position **/
class Point2D {
private:
    int m_x;  /** < X coordinate of the object **/
    int m_y;  /** < Y coordinate of the object **/

public:
    ~Point2D();
    Point2D(int initX, int initY);
    
    /** Used to get the x position of the point
     *
     *  @return The x coordinate of the point 
     */
    int GetX() { return m_x; }
    
    /** Used to get the y position of the point
     *
     *  @return The y coordinate of the point 
     */
    int GetY() { return m_y; }
    
    /** Adds a value to the x coordinate of the point.  Used to update the horizontal position of an object
     *
     *  @param xOffset The value to add to the x coordinate
     */
    void AddX(int xOffset) { m_x += xOffset; }
    
    /** Adds a value to the y coordinate of the point.  Used to update the horizontal position of an object
     *
     *  @param yOffset The value to add to the y coordinate
     */
    void AddY(int yOffset) { m_y += yOffset; }
    
    /** Sets the x coordinate of the point to a passed value
     *
     *  @param newX The new x coordinate of the point
     */
    void SetX(int newX) { m_x = newX; }
    
    /** Sets the y coordinate of the point to a passsed value
     *
     *  @param newY The new y coordinate of the point
     */
    void SetY(int newY) { m_y = newY; }
};

#endif
