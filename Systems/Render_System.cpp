/*
 * Render_System.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/30/13
 * Organization:    n8Tech
 *
*/

#include "Render_System.h"
#include "n8.h"
#include <iostream>

using namespace std;

/** Default Destructor
 */
Render_System::~Render_System(){
    
}

/** Default Constructor <p>
 *  Defines the system requirements of DRAWABLE, and POSITION and sets id_ to RENDER_SYSTEM.  Initializes the camera_ and screen_ pointers to NULL.
 */
Render_System::Render_System(Game_Manager* gameManager){
    requirements_[DRAWABLE] = 1;
    requirements_[POSITION] = 1;
    id_ = RENDER_SYSTEM;
    camera_ = NULL;
    screen_ = NULL;
    game_ = gameManager;
}

/** Used to store a pointer to the screen entity that will be used as the canvas for all drawing operations.
 *  Checks that the passed entity has a POSITION and DRAWABLE component which are needed to act as the screen.
 *  @param newEntity The pointer to the screen entity
 *
 *  @see Position_Component
 *  @see Drawable_Component
 *  @see Entity
 */
bool Render_System::register_screen_entity(Entity* newEntity){
    if (newEntity->get_component(POSITION) && newEntity->get_component(DRAWABLE)) {
        screen_ = newEntity;
        return true;
    }
    
    return false;
}

/** Used to store a pointer to the camera entity that will be used for all drawing operations.
 *  Checks that the passed entity has a POSITION component which is needed to act as the camera.
 *  @param newEntity The pointer to the screen entity
 *
 *  @see Position_Component
 *  @see Entity
 */
bool Render_System::register_camera_entity(Entity* newEntity){
    if (newEntity->get_component(POSITION) ) {
        camera_ = newEntity;
        return true;
    }
    
    return false;
}

/** Draws a source SDL_Surface to a destination SDL_Surface.  Used to draw sprite images to the SDL_Surface stored by screen_.
 *
 *  @param x The x location where the source SDL_Surface should be drawn
 *  @param y The y location where the source SDL_Surface should be drawn
 *  @param source The image to be drawn to the screen
 *  @param destination The canvas SDL_Surface that images are drawn to
 */
void Render_System::draw_image( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;
    
    //Give the offsets to the rectangle
    offset.x = x;
    offset.y = y;
    
    //Blit the surface
    SDL_BlitSurface( source, NULL, destination, &offset );
}

/** Used to render all registered entities to the screen.  This is what renders each game scene.
 */
void Render_System::render(){
    
    if (screen_ != NULL) {
        
        if (n8::get_drawable_component(screen_) != NULL) {
            SDL_Surface* screen_surface = n8::get_drawable_component(screen_)->get_image();
            SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 0, 0, 0));
            int xOffset = 0;
            int yOffset = 0;
            if (camera_ != NULL && n8::get_position_component(camera_) != NULL) {
                xOffset = n8::get_position_component(camera_)->get_x();
                yOffset = n8::get_position_component(camera_)->get_y();
            }
            cout << "x offset: " << xOffset << endl;
            
            map<int, Entity*>::iterator ii;
            for (ii = registered_entities_map_.begin(); ii != registered_entities_map_.end(); ii++) {
                draw_image( n8::get_position_component(ii->second)->get_x() - xOffset, 
                           n8::get_position_component(ii->second)->get_y() - yOffset, 
                           n8::get_drawable_component(ii->second)->get_image(), 
                           screen_surface);
                
            }
            
            SDL_Flip( screen_surface );
        }
        
    }

}

/** Updates all registered components. Currently, does nothing unless DEBUG_MODE and DEBUG_UPDATE are both true in which case the id of each registered entity is output to the console.
 */
void Render_System::update(){
    if (DEBUG_MODE && DEBUG_UPDATE) {
        cout << "    RENDER_SYSTEM.Update()" << registered_entities_map_.size() << endl;
        map<int, Entity*>::iterator ii;
        for (ii = registered_entities_map_.begin(); ii != registered_entities_map_.end(); ii++) {            
            Name_Component* name = (Name_Component*)ii->second->get_component(NAME);
            if (name == NULL) {
                cout << "      " << ii->second->get_id() << endl;
            }
            else{
                cout << "      " << name->get_name() << endl;   
            }
        }
    }
}