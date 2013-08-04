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
    
/*** Create the screen and register it ***/
    cEntity* entScreen = game->create_screen_entity(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP);
    game->load_images("/Users/lcballa44/Desktop/n8/n8/Assets/gfx/images.txt");
    
    //The surfaces that will be used
    cSprite* message = NULL;
    cSprite* background = NULL;
        
    //Set the window caption
    SDL_WM_SetCaption( "Hello World", NULL );
    
    //Load the images
    
    message = game->get_sprite("/Users/lcballa44/Desktop/n8/n8/Assets/gfx/hello.bmp");
    background = game->get_sprite( "/Users/lcballa44/Desktop/n8/n8/Assets/gfx/background.bmp" );
    
    if (message == NULL || message->get_image() == NULL) {
        cout << "message null" << endl;
    }
    
    if (background == NULL || background->get_image()==NULL) {
        cout << "background null" << endl;
    }
    

    
/*** Create 2 user entities ***/
    cEntity* nate = game->create_user_entity(n8::get_next_id(), "Nate", 0, 0, message);
    game->create_user_entity(n8::get_next_id(), "Megan", 0, 0, message);
  
    

/*** GAME LOOP ***/
    
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




