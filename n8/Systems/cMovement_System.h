/*
 * cMovement_System.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            8/4/13
 * Organization:    n8Tech
 *
 */

#ifndef n8_cMovement_System_h
#define n8_cMovement_System_h

#include "cSystem.h"

class cMovement_System : public cSystem{
   
private:
    int world_width;
    int world_height;
    
    bool inside_world_bounds(cEntity* ent, int xOffset, int yOffset);
    
public:
    
    ~cMovement_System();
    cMovement_System();
    
    void update();
    
    void right();
    void down();
    void left();
    void up();
    
    void set_world_bounds(int w, int h);

};

#endif
