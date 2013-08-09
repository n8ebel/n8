/*
 * Movement_System.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            8/4/13
 * Organization:    n8Tech
 *
 */

#ifndef n8_Movement_System_h
#define n8_Movement_System_h

#include "System.h"

class Movement_System : public System{
   
private:
    int world_width_;
    int world_height_;
    
    bool inside_world_bounds(Entity* ent, int xOffset, int yOffset);
    
public:
    
    ~Movement_System();
    Movement_System();
    
    void update();
    
    void right();
    void down();
    void left();
    void up();
    
    void set_world_bounds(int w, int h);

};

#endif
