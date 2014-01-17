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
RenderSystem::~RenderSystem(){
    
}

/** Default Constructor <p>
 *  Defines the system requirements of DRAWABLE, and POSITION and sets id_ to RENDER_SYSTEM.  Initializes the camera_ and screen_ pointers to NULL.
 */
RenderSystem::RenderSystem(){
    m_systemRequirements[DRAWABLE] = 1;
    m_systemRequirements[POSITION] = 1;
    m_id = RENDER_SYSTEM ;
}

/** Used to add a base layer entity to the render system to be used to draw the game background
 *
 *	@param newLayer The background entity to draw
 */
void RenderSystem::AddBaseLayer(Entity* newLayer) {
    m_baseLayers.push_back( newLayer );
}




/** Used to render all registered entities to the screen.  This is what renders each game scene.
 */
void RenderSystem::Render(SDL_Surface* screen){
    Log::Debug("RENDER SYSTEM", ".Render()");

    /*
    Log::debug(id_ + ".render", "Start");
    if (screen != NULL) {
        
		int cameraX = 0;
		int cameraY = 0;
		int cameraW = 0;
		int cameraH = 0;
		
        if (n8::get_drawable_component(screen) != NULL) {
            SDL_Surface* screen_surface = n8::get_drawable_component(screen)->get_image();
			Color_Component* color = static_cast<Color_Component*>(screen->get_component(COLOR));
            SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, color->get_red(), color->get_green(),color->get_blue()));
			
			
            if (camera_ != NULL && n8::get_position_component(camera_) != NULL) {
                cameraX = n8::get_position_component(camera_)->get_x();
				cameraY = n8::get_position_component(camera_)->get_y();
				cameraW = n8::get_position_component(camera_)->get_width();
				cameraH = n8::get_position_component(camera_)->get_height();
            }
			
			// Draw background layers
			for(int i =0; i < base_layers_.size(); i++){
                Log::Debug(id_ + ".render", "Updating Entity: " + Numerical_Utilities::num_to_string(base_layers_[i]->get_id()));
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
				Log::Debug(id_ + ".render", "Updating Entity: " + Numerical_Utilities::num_to_string(ii->second->get_id()));
				static_cast<Drawable_Component*>(ii->second->get_component(DRAWABLE))->get_sprite()->draw( n8::get_position_component(ii->second)->get_x() - cameraX, n8::get_position_component(ii->second)->get_y() - cameraY, screen_surface);
                
            }
            
            SDL_Flip( screen_surface );
        }
        
    }
    Log::Debug(id_ + ".render", "End");
     */
}

/** Updates all registered components. Currently, does nothing unless DEBUG_MODE and DEBUG_UPDATE are both true in which case the id of each registered entity is output to the console.
 */
void RenderSystem::Update(){}

bool RenderSystem::RegisterEntity(Entity* newEntity){
    
    return false;
}

void RenderSystem::UnregisterEntity(int id){
    
}
