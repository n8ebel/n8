//
//  main.cpp
//  n8
//
//  Created by Nate Ebel on 7/26/13.
//  Copyright (c) 2013 n8Tech. All rights reserved.
//

#include "SDL/SDL.h"
#include "n8.h"
#include "Game_Manager.h"
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
    Game_Manager* game = new Game_Manager();
    if(game->initializeSDL()){ cout << "SDL initialized" << endl; }
    else{ cout << "SDL not initialized" << endl; }  

/***  Set the window caption  ***/
    SDL_WM_SetCaption( "n8", NULL );
    
/*** Set up the game systems ***/
    
    /* Create a base system */
    System* baseSystem = game->create_system(BASE_SYSTEM);
    if( baseSystem == NULL){
        n8::log_error("Main","Game manager wasn't initialized");
    }
    else{
        n8::log_info("Main","Game manager was initialized");
    }
    
    /* Create a render system */
    Render_System* renderSystem = (Render_System*)game->create_system(RENDER_SYSTEM);
    if (renderSystem == NULL) {
        n8::log_error("Main","Render system wasn't initialized");
    }
    else{
        n8::log_info("Main","Render system was initialized");
    }
    
    /* Create a movement system */
    Movement_System* movementSystem = (Movement_System*)game->create_system(MOVEMENT_SYSTEM);
    if (movementSystem == NULL) {
        n8::log_error("Main","Movement system wasn't initialized");
    }
    else{
        n8::log_info("Main","Movement system was initialized");
        //movementSystem->set_world_bounds(1000, 750);
    }
    
    /* Create a movement system */
    Camera_System* cameraSystem = (Camera_System*)game->create_system(CAMERA_SYSTEM);
    if (cameraSystem == NULL) {
        n8::log_error("Main","Camera system wasn't initialized");
    }
    else{
        n8::log_info("Main","Camera system was initialized");
    }
    
    game->set_world_bounds(1000, 750);
    
/*** Create the screen and register it ***/
    Entity* entScreen = game->create_screen_entity(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP);
    renderSystem->register_screen_entity(entScreen);
    
/*** Create the camera entity ***/
    Entity* entCamera = game->create_camera_entity(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    cameraSystem->register_camera_entity(entCamera);
    renderSystem->register_camera_entity(entCamera);

/*** Load image resources ***/
    game->load_images("/Users/lcballa44/Desktop/n8/n8/Assets/gfx/images.txt");
    Sprite* message = game->get_sprite("/Users/lcballa44/Desktop/n8/n8/Assets/gfx/hello.bmp");
    Sprite* background = game->get_sprite( "/Users/lcballa44/Desktop/n8/n8/Assets/gfx/background.bmp" );
    

/*** Create background entity ***/
    Entity* entBackground = new Entity(n8::get_next_id());
    entBackground->add_component(new Position_Component(POSITION, 0, 0));
    entBackground->add_component(new Drawable_Component(DRAWABLE, background));
    game->register_entity(entBackground);
    
/*** Create user controlled entity ***/
    Entity* nate = game->create_user_entity(n8::get_next_id(), "Nate", 0, 0, message);
    cameraSystem->register_entity_to_follow(nate);

  
/*** GAME LOOP ***/
    game->initializeGameLoop();
    
    while (game->is_running()) {
        game->handle_input();
        
        /*** Update the game logic ***/
        game->get_system(MOVEMENT_SYSTEM)->update();
        game->get_system(CAMERA_SYSTEM)->update();
        game->get_system(RENDER_SYSTEM)->update();
        
        /*** Render the frame ***/
        //n8::get_render_system(game)->render();  
        renderSystem->render();
        
    }
    
    
    delete game;
    
    //Quit SDL
    SDL_Quit();
    
    //Return
    return 0;
}




