/*
 * cCamera_System.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            8/5/13
 * Organization:    n8Tech
 *
 */

#ifndef n8_cCamera_System_h
#define n8_cCamera_System_h

#include "cSystem.h"

class cCamera_System : public cSystem{

private:
    cEntity* entity_to_follow;
    cEntity* camera;
    //cEntity* screen;
    
    int world_width;
    int world_height;
    
public:
    ~cCamera_System();
    cCamera_System();
    
    bool register_entity_to_follow(cEntity* newEntity);
    bool register_camera_entity(cEntity* newEntity);
    //bool register_screen_entity(cEntity* newEntity);
    
    void set_world_bounds(int w, int h);
    
    void update();
    
};

#endif
