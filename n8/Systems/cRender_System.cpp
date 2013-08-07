/*
 * cRender_System.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/30/13
 * Organization:    n8Tech
 *
*/

#include "cRender_System.h"
#include "n8.h"
#include <iostream>

using namespace std;

cRender_System::~cRender_System(){
    
}

cRender_System::cRender_System(){
    requirements[DRAWABLE] = 1;
    requirements[POSITION] = 1;
    ID = RENDER_SYSTEM;
    camera = NULL;
    screen = NULL;
}


bool cRender_System::register_screen_entity(cEntity* newEntity){
    if (newEntity->get_component(POSITION) && newEntity->get_component(DRAWABLE)) {
        screen = newEntity;
        return true;
    }
    
    return false;
}

bool cRender_System::register_camera_entity(cEntity* newEntity){
    if (newEntity->get_component(POSITION) ) {
        camera = newEntity;
        return true;
    }
    
    return false;
}

void cRender_System::draw_image( int x, int y, SDL_Surface* source, SDL_Surface* destination )
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
void cRender_System::render(){
    
    
    SDL_Surface* screen_surface = n8::get_drawable_component(screen)->get_image();
    SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 0, 0, 0));
    
    int xOffset = n8::get_position_component(camera)->get_x();
    int yOffset = n8::get_position_component(camera)->get_y();
    
    /*** Draw images to the screen ***/
    for (int i = 0; i < registered_entities.size(); i++) {
        
        draw_image( n8::get_position_component(registered_entities[i])->get_x() - xOffset, n8::get_position_component(registered_entities[i])->get_y() - yOffset, 
                    n8::get_drawable_component(registered_entities[i])->get_image(), screen_surface);
         
    }
    
    //Update the screen
    SDL_Flip( n8::get_drawable_component(screen)->get_image() );

}

/** update
 *
 *  Use-    Overrides the base system update method
 *          Used to update any render specific component data
 *
 */
void cRender_System::update(){
    if (DEBUG_MODE && DEBUG_UPDATE) {
        cout << "    RENDER_SYSTEM.Update()" << registered_entities.size() << endl;
        for (int i = 0; i < registered_entities.size(); i++) {
            cName_Component* name = (cName_Component*)registered_entities[i]->get_component(NAME);
            if (name == NULL) {
                cout << "      " << registered_entities[i]->get_id() << endl;
            }
            else{
                cout << "      " << name->get_name() << endl;   
            }
        }
    }
}