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

class Entity;

/** Responsible for drawing all entities to the screen.  Manages a screen and camera
 *  entity to control what is drawn where. These two special entities are explicitly
 *  registered with the system.  Other drawable entities are registered at creation
 *  and will be drawn if they meet the system requirements.
 */
class RenderSystem : public System {

private:
    
    vector<Entity*> m_baseLayers;	/** < List of base layer entities used to draw game backgrounds **/
    
public:
    ~RenderSystem();
    RenderSystem();
    
    void Update();
    void Render(SDL_Surface*);
    
    virtual bool RegisterEntity(Entity* newEntity) ;
    virtual void UnregisterEntity(int ID) ;
	
	
	void AddBaseLayer(Entity* newLayer);
    
};


#endif
