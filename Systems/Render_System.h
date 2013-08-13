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

class Game_Manager;

/** Responsible for drawing all entities to the screen.  Manages a screen and camera
 *  entity to control what is drawn where. These two special entities are explicitly
 *  registered with the system.  Other drawable entities are registered at creation
 *  and will be drawn if they meet the system requirements.
 */
class Render_System : public System {

private:
    Entity* screen_;    /** < Pointer to the screen entity **/
    Entity* camera_;    /** < Pointer to the camera entity **/
    
public:
    ~Render_System();
    Render_System(Game_Manager* gameManager);
    
    void update();
    void render();
    
    bool register_screen_entity(Entity* newEntity);
    bool register_camera_entity(Entity* newEntity);
    
    void draw_image( int x, int y, SDL_Surface* source, SDL_Surface* destination );
    
};


#endif
