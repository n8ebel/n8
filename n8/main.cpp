//
//  main.cpp
//  n8
//
//  Created by Nate Ebel on 7/26/13.
//  Copyright (c) 2013 n8Tech. All rights reserved.
//

#include "SDL/SDL.h"
#include "n8.h"
#include "constants.h"
#include <iostream>

using namespace std;

//The attributes of the screen
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

SDL_Surface* load_image(string);
void apply_surface(int,int, SDL_Surface*, SDL_Surface*);

int main( int argc, char* argv[] )
{   
    /*** Create the game manager ****/
    cGame_Manager* game = new cGame_Manager();
    if(game->initializeSDL()){
        cout << "SDL initialized" << endl;
    }
    else
    {
        cout << "SDL not initialized" << endl;
    }   
    
    /*** Create the screen and register it ***/
    cEntity* entScreen = game->create_screen_entity(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP);
    game->get_resource_handler()->load_images("/Users/lcballa44/Desktop/n8/n8/Assets/gfx/images.txt");
    
    //The surfaces that will be used
    cSprite* message = NULL;
    cSprite* background = NULL;
        
    //Set the window caption
    SDL_WM_SetCaption( "Hello World", NULL );
    
    //Load the images
    
    message = game->get_resource_handler()->get_sprite("/Users/lcballa44/Desktop/n8/n8/Assets/gfx/hello.bmp");
    background = game->get_resource_handler()->get_sprite( "/Users/lcballa44/Desktop/n8/n8/Assets/gfx/background.bmp" );
    
    if (message == NULL || message->get_image() == NULL) {
        cout << "message null" << endl;
    }
    
    if (background == NULL || background->get_image()==NULL) {
        cout << "background null" << endl;
    }
    
/*** Set up the game systems ***/
    
    /* Create a base system */
    cSystem* baseSystem = game->create_system(BASE_SYSTEM);
    if( baseSystem == NULL){
        n8::log_error("Game manager wasn't initialized");
    }
    else{
        n8::log_info("Game manager was initialized");
    }
    
    /* Create a render system */
    cRender_System* renderSystem = (cRender_System*)game->create_system(RENDER_SYSTEM);
    if (renderSystem == NULL) {
        n8::log_error("Render system wasn't initialized");
    }
    else{
        n8::log_info("Render system was initialized");
    }
    
/*** Create 2 user entities ***/
    cEntity* nate = game->create_user_entity(n8::get_next_id(), "Nate", 0, 0, message);
    game->create_user_entity(n8::get_next_id(), "Megan", 0, 0, message);
  
/*** Create a generic entity with only a position ***/
    cEntity* test = new cEntity(n8::get_next_id());
    test->add_component(new cPosition_Component(POSITION, 0, 0));
    game->register_entity(test);
    

    
    
    
    //Apply the background to the screen
    apply_surface( 0, 0, background->get_image(), n8::get_drawable_component(entScreen)->get_sprite()->get_image() );
    apply_surface( 320, 0, background->get_image(), n8::get_drawable_component(entScreen)->get_sprite()->get_image() );
    apply_surface( 0, 240, background->get_image(), n8::get_drawable_component(entScreen)->get_sprite()->get_image() );
    apply_surface( 320, 240, background->get_image(), n8::get_drawable_component(entScreen)->get_sprite()->get_image() );
    
    
    //Apply the message to the screen
    apply_surface( 180, 140, n8::get_drawable_component(nate)->get_sprite()->get_image(), n8::get_drawable_component(entScreen)->get_sprite()->get_image() );
    
    //Update the screen
    if( SDL_Flip( n8::get_drawable_component(entScreen)->get_sprite()->get_image() ) == -1 )
    {
        return 1;    
    }
    
    
    game->initializeGameLoop();
   
    while (game->is_running()) {
        game->handle_input();
        
        
    /*** Update the game logic ***/
        game->get_system(BASE_SYSTEM)->update();
        //game->get_system(COLLISION_SYSTEM)->update();
        //game->get_system(INTERACTION_SYSTEM)->update();
        game->get_system(RENDER_SYSTEM)->update();
        
    /*** Render the frame ***/
        ((cRender_System*)game->get_system(RENDER_SYSTEM))->render();
        
        //cout << endl;
    }
    
    
    
    
    delete game;
    
    //Quit SDL
    SDL_Quit();
    
    //Return
    return 0;
}



void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;
    
    //Give the offsets to the rectangle
    offset.x = x;
    offset.y = y;
    
    //Blit the surface
    SDL_BlitSurface( source, NULL, destination, &offset );
}
