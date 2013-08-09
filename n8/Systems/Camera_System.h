/*
 * Camera_System.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            8/5/13
 * Organization:    n8Tech
 *
 */

#ifndef n8_Camera_System_h
#define n8_Camera_System_h

#include "System.h"

class Camera_System : public System{

private:
    Entity* entity_to_follow_;
    Entity* camera_;
    //Entity* screen;
    
    int world_width_;
    int world_height_;
    
public:
    ~Camera_System();
    Camera_System();
    
    bool register_entity_to_follow(Entity* newEntity);
    bool register_camera_entity(Entity* newEntity);
    //bool register_screen_entity(Entity* newEntity);
    
    void set_world_bounds(int w, int h);
    
    void update();
    
};

#endif
