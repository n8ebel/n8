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
    ID = BASE_SYSTEM;
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
    
    cEntity* screen = registered_entities[0];
    SDL_Surface* screen_surface = n8::get_drawable_component(screen)->get_image();
    SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 0, 0, 0));
    
    /*** Draw images to the screen ***/
    for (int i = 0; i < registered_entities.size(); i++) {
        
        draw_image( n8::get_position_component(screen)->get_x(), n8::get_position_component(screen)->get_y(), 
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
    if (DEBUG_MODE) {
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