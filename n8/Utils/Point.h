/*
 * Point.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

#ifndef SDL_Test_Point_h
#define SDL_Test_Point_h

class Point {
private:
    int x_;
    int y_;

public:
    ~Point();
    Point();
    Point(int initX, int initY);
    int get_x();
    int get_y();
    void add_x(int xOffset);
    void add_y(int yOffset);
    void set_x(int newX);
    void set_y(int newY);
};

#endif
