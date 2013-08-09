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

Render_System::~Render_System(){
    
}

Render_System::Render_System(){
    requirements_[DRAWABLE] = 1;
    requirements_[POSITION] = 1;
    id_ = RENDER_SYSTEM;
    camera_ = NULL;
    screen_ = NULL;
}


bool Render_System::register_screen_entity(Entity* newEntity){
    if (newEntity->get_component(POSITION) && newEntity->get_component(DRAWABLE)) {
        screen_ = newEntity;
        return true;
    }
    
    return false;
}

bool Render_System::register_camera_entity(Entity* newEntity){
    if (newEntity->get_component(POSITION) ) {
        camera_ = newEntity;
        return true;
    }
    
    return false;
}

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

/** render
 *
 *  Use-    Renders the game frames
 *
 */
void Render_System::render(){
    
    
    SDL_Surface* screen_surface = n8::get_drawable_component(screen_)->get_image();
    SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 0, 0, 0));
    
    int xOffset = n8::get_position_component(camera_)->get_x();
    int yOffset = n8::get_position_component(camera_)->get_y();
    
    /*** Draw images to the screen ***/
    for (int i = 0; i < registered_entities_.size(); i++) {
        
        draw_image( n8::get_position_component(registered_entities_[i])->get_x() - xOffset, n8::get_position_component(registered_entities_[i])->get_y() - yOffset, 
                    n8::get_drawable_component(registered_entities_[i])->get_image(), screen_surface);
         
    }
    
    //Update the screen
    SDL_Flip( n8::get_drawable_component(screen_)->get_image() );

}

/** update
 *
 *  Use-    Overrides the base system update method
 *          Used to update any render specific component data
 *
 */
void Render_System::update(){
    if (DEBUG_MODE && DEBUG_UPDATE) {
        cout << "    RENDER_SYSTEM.Update()" << registered_entities_.size() << endl;
        for (int i = 0; i < registered_entities_.size(); i++) {
            Name_Component* name = (Name_Component*)registered_entities_[i]->get_component(NAME);
            if (name == NULL) {
                cout << "      " << registered_entities_[i]->get_id() << endl;
            }
            else{
                cout << "      " << name->get_name() << endl;   
            }
        }
    }
}