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

class Game_Manager;
/** Operates on game entites that need to move around the screen.  Also tracks
 *  the size of the current world to ensure entities don't move outside the bounds
 *  of the game world.
 */
class Movement_System : public System{
   
private:
    int world_width_;       /** < The pixel width of the current game world.  Used to determine the bounds in which an entity can move  **/
    int world_height_;      /** < The pixel height of the current game world.  Used to determine the bounds in which an entity can move  **/
    
    bool inside_world_bounds(Entity* ent, int xOffset, int yOffset);
    
    Entity* user_entity_;
    
public:
    
    ~Movement_System();
    Movement_System(Game_Manager* gameManager);
    
    void update();
    
    void right();
    void down();
    void left();
    void up();
    void move(int x, int y);
    
    void set_world_bounds(int w, int h) { world_width_ = w; world_height_ = h; }
    void register_user_entity(Entity* userEntity);

    /** Gets a pointer to the entity being controlled by the user
     *
     * 	@return A pointer to an entity
     */
    Entity* get_user_entity() { return user_entity_; }

};

#endif
