/*
 * Render_System.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/30/13
 * Organization:    n8Tech
 *
 */

#ifndef n8_Render_System_h
#define n8_Render_System_h

#include "System.h"
#include "SDL/SDL.h"

class Render_System : public System {

private:
    Entity* screen_;
    Entity* camera_;
    
public:
    ~Render_System();
    Render_System();
    
    void update();
    void render();
    
    bool register_screen_entity(Entity* newEntity);
    bool register_camera_entity(Entity* newEntity);
    
    void draw_image( int x, int y, SDL_Surface* source, SDL_Surface* destination );
    
};


#endif
