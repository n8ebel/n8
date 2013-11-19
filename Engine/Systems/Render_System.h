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

#include <vector>

#include "System.h"
#include "SDL/SDL.h"

class Game_Manager;
class Entity;

/** Responsible for drawing all entities to the screen.  Manages a screen and camera
 *  entity to control what is drawn where. These two special entities are explicitly
 *  registered with the system.  Other drawable entities are registered at creation
 *  and will be drawn if they meet the system requirements.
 */
class Render_System : public System {

private:
    Entity* screen_;    /** < Pointer to the screen entity **/
    Entity* camera_;    /** < Pointer to the camera entity **/
	vector<Entity*> base_layers_;	/** < List of base layer entities used to draw game backgrounds **/
    
public:
    ~Render_System();
    Render_System(Game_Manager* gameManager);
    
    void update();
    void render();
    
    bool register_screen_entity(Entity* newEntity);
    bool register_camera_entity(Entity* newEntity);
	
	/** Used to add a base layer entity to the render system to be used to draw the game background
	*
	*	@param newLayer The background entity to draw
	*/
	void add_base_layer(Entity* newLayer) { base_layers_.push_back( newLayer ); }
    
    bool draw_image( int x, int y, SDL_Surface* source, SDL_Surface* destination );
	bool draw_image( int x, int y, int x2, int y2, int width, int height, SDL_Surface* source, SDL_Surface* dest);
    
};


#endif
