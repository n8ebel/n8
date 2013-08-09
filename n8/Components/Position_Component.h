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
    Point* position_;
    
public:
    ~Position_Component();
    Position_Component(string newID, Point* newPosition);
    Position_Component(string newID, int initX, int initY);
    
    
    Point* get_position();
    int get_x();
    int get_y();
    
    void update_position(int xOffset, int yOffset);
};

#endif
