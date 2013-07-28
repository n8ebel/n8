/*
 * cPoint.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

#ifndef SDL_Test_cPoint_h
#define SDL_Test_cPoint_h

class cPoint {
private:
    int x;
    int y;

public:
    ~cPoint();
    cPoint();
    cPoint(int initX, int initY);
    int get_x();
    int get_y();
    void add_x(int xOffset);
    void add_y(int yOffset);
    void set_x(int newX);
    void set_y(int newY);
};

#endif
