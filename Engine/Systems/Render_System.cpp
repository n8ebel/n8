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
	if(DEBUG_){
		Log::debug(id_ + ".register_screen_entity", "Entity: " + Numerical_Utilities::num_to_string(newEntity->get_id()));
	}
    if (newEntity->get_component(POSITION) != NULL && newEntity->get_component(DRAWABLE) != NULL) {
        screen_ = newEntity;
        if(DEBUG_){
        	Log::debug(id_ + ".register_screen_entity", "PASS");
		}
        return true;
    }
    
    if(DEBUG_){
    	Log::debug(id_ + ".register_screen_entity", "FAIL");
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
	if(DEBUG_){
		Log::debug(id_ + ".register_camera_entity", "Entity: " + Numerical_Utilities::num_to_string(newEntity->get_id()));
	}
    if (newEntity->get_component(POSITION) ) {
        camera_ = newEntity;
        if(DEBUG_){
        	Log::debug(id_ + ".register_camera_entity", "PASS");
		}
        return true;
    }
    
    if(DEBUG_){
    	Log::debug(id_ + ".register_camera_entity", "FAIL");
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
bool Render_System::draw_image( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
	if( source == NULL || destination == NULL){
		return false;
	}
	
    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;
    
    //Give the offsets to the rectangle
    offset.x = x;
    offset.y = y;
	
    
    //Blit the surface
    SDL_BlitSurface( source, NULL, destination, &offset );
	
	return true;
}

/** Used to draw part of a source image to the screen.  The size of the sub-image is given
 *	along with the coordinates in the source image to take the sub image from.  Specifying
 *  x2 = 0, y2=0, width = 50, height=50 would take the top left 50x50 portion of the source image.
 *
 *  @param x The x location where the sub-image should be drawn
 *  @param y The y location where the sub-image should be drawn
 *  @param x2 The x location for the sub-image to be taken from the source image
 *  @param y2 The y location for the sub-image to be taken from the source image
 *	@param width The width of the sub-image
 *	@param height The height of the sub-image
 *  @param source The image that the sub-image will be taken from.
 *  @param destination The canvas SDL_Surface that images are drawn to
 */
bool Render_System::draw_image( int x, int y, int x2, int y2, int width, int height, SDL_Surface* source, SDL_Surface* destination){

	if( source == NULL || destination == NULL){
		return false;
	}
	
    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;
    
    //Give the offsets to the rectangle
    offset.x = x;
    offset.y = y;
	
	SDL_Rect srcR;
	
	srcR.x = x2;
	srcR.y = y2;
	srcR.w = width;
	srcR.h = height;
	
	
    
    //Blit the surface
    SDL_BlitSurface( source, &srcR, destination, &offset );
	
	return true;
}

/** Used to render all registered entities to the screen.  This is what renders each game scene.
 */
void Render_System::render(){
    Log::debug(id_ + ".render", "Start");
    if (screen_ != NULL) {
        
		int cameraX = 0;
		int cameraY = 0;
		int cameraW = 0;
		int cameraH = 0;
		
        if (n8::get_drawable_component(screen_) != NULL) {
            SDL_Surface* screen_surface = n8::get_drawable_component(screen_)->get_image();
			Color_Component* color = static_cast<Color_Component*>(screen_->get_component(COLOR));
            SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, color->get_red(), color->get_green(),color->get_blue()));
			
			
            if (camera_ != NULL && n8::get_position_component(camera_) != NULL) {
                cameraX = n8::get_position_component(camera_)->get_x();
				cameraY = n8::get_position_component(camera_)->get_y();
				cameraW = n8::get_position_component(camera_)->get_width();
				cameraH = n8::get_position_component(camera_)->get_height();
            }
			
			// Draw background layers
			for(int i =0; i < base_layers_.size(); i++){
                Log::debug(id_ + ".render", "Updating Entity: " + Numerical_Utilities::num_to_string(base_layers_[i]->get_id()));
				Sprite* image_ = static_cast<Drawable_Component*>(base_layers_[i]->get_component(DRAWABLE))->get_sprite();
				
                
                int numHorizontal = 0;
                if ( (cameraX + cameraW) % image_->get_width() == 0){
                    numHorizontal = (cameraX + cameraW) / image_->get_width();
                }
                else{
                    numHorizontal = (cameraX + cameraW) / image_->get_width() + 1;
                }
                int numVertical = 0;
                if ( (cameraY + cameraH) % image_->get_height() == 0){
                    numVertical = (cameraY + cameraH) / image_->get_height();
                }
                else{
                    numVertical = (cameraY + cameraH) / image_->get_height() + 1;
                }
                
                int drawX = 0 - (cameraX % image_->get_width());
                int drawY = 0 - (cameraY % image_->get_height());
                
                for (int i = 0; i < numHorizontal; i++) {
                    for (int j = 0; j < numVertical; j++) {
                        image_->draw( drawX + i * image_->get_width(), drawY + j*image_->get_height(), screen_surface);
                    }
                    
                }
				
				
                
                image_ = NULL;
                delete image_;
			}
			
            
            
            map<int, Entity*>::iterator ii;
            for (ii = registered_entities_map_.begin(); ii != registered_entities_map_.end(); ii++) {
				/*
                draw_image( n8::get_position_component(ii->second)->get_x() - xOffset, 
                           n8::get_position_component(ii->second)->get_y() - yOffset, 
                           n8::get_drawable_component(ii->second)->get_image(), 
                           screen_surface);
				*/
                Log::debug(id_ + ".render", "Updating Entity: " + Numerical_Utilities::num_to_string(ii->second->get_id()));
				static_cast<Drawable_Component*>(ii->second->get_component(DRAWABLE))->get_sprite()->draw( n8::get_position_component(ii->second)->get_x() - cameraX, n8::get_position_component(ii->second)->get_y() - cameraY, screen_surface);
                
            }
            
            SDL_Flip( screen_surface );
        }
        
    }
    Log::debug(id_ + ".render", "End");
}

/** Updates all registered components. Currently, does nothing unless DEBUG_MODE and DEBUG_UPDATE are both true in which case the id of each registered entity is output to the console.
 */
void Render_System::update(){
    if (DEBUG_UPDATE_) {
    	Log::debug(id_ + ".update", "");

        map<int, Entity*>::iterator ii;
        for (ii = registered_entities_map_.begin(); ii != registered_entities_map_.end(); ii++) {            
        	Log::debug(id_ + ".update", "Updating Entity: " + Numerical_Utilities::num_to_string(ii->second->get_id()));
        }
    }
}
