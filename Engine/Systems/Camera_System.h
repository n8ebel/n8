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
#include "n8.h"
#include "Numerical_Utilities.h"

class Game_Manager;

/** Operates on the game's camera if it exists.  The point of the camera is to control what
 *  portion of the game's world is currently being drawn to the screen.  The default behavior
 *  is to follow a user entity around so the entity is always displayed in the middle of the
 *  screen.  When the camera's edges move beyond the bounds of the game world, the camera is
 *  clamped to the edges of the world, and therefore the entity will appear to move from the
 *  middle of the screen to other areas.
 */
class Camera_System : public System{

private:
    Entity* entity_to_follow_;  /** < A pointer to an entity that the camera will follow **/
    Entity* camera_;            /** < A pointer to a camera entity that will update based on the position of entity_to_follow_. **/
    
    
    int world_width_;   /** < The pixel width of the current game world.  Used to determine the bounds in which an entity can move  **/ 
    
    int world_height_;  /** < The pixel height of the current game world.  Used to determine the bounds in which an entity can move  **/
    
public:
    ~Camera_System();
    Camera_System(Game_Manager* gameManager);
    
    bool register_entity_to_follow(Entity* newEntity);
    bool register_camera_entity(Entity* newEntity);
    void update();
    
    /** Sets the height and width of the current game world
     *
     *  @param w The width of the current game world
     *  @param h The height of the current game world
     */
    void set_world_bounds(int w, int h) { world_width_ = w; world_height_ = h; }
    
};

#endif
