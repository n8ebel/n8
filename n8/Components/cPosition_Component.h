/*
 * cPosition_Component.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

#ifndef SDL_Test_cPosition_Component_h
#define SDL_Test_cPosition_Component_h

#include "cPoint.h"

using namespace std;

class cPosition_Component : public cComponent {
private:
    cPoint* position;
    int width;
    int height;
    
public:
    ~cPosition_Component();
    cPosition_Component(string newID, cPoint* newPosition);
    cPosition_Component(string newID, int initX, int initY);
    cPosition_Component(string newID, cPoint* newPosition, int w, int h);
    cPosition_Component(string newID, int initX, int initY, int w, int h);
    
    
    cPoint* get_position();
    int get_x();
    int get_y();
    int get_width();
    int get_height();
    
    void update_position(int xOffset, int yOffset);
};

#endif
