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

SDL_Surface* load_image(string);
void apply_surface(int,int, SDL_Surface*, SDL_Surface*);

int main( int argc, char* argv[] )
{   
    
    
    
    
    //The attributes of the screen
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    const int SCREEN_BPP = 32;
    
    //The surfaces that will be used
    SDL_Surface *message = NULL;
    SDL_Surface *background = NULL;
    SDL_Surface *screen = NULL;
        
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return 1;    
    }
    
    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
    
    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return 1;    
    }
    
    //Set the window caption
    SDL_WM_SetCaption( "Hello World", NULL );
    
    //Load the images
    message = load_image("/Users/lcballa44/Projects/SDL_Test/SDL_Test/Assets/gfx/hello.bmp");
    background = load_image( "/Users/lcballa44/Projects/SDL_Test/SDL_Test/Assets/gfx/background.bmp" );
    
    
    cSprite* sprite = new cSprite("/Users/lcballa44/Projects/SDL_Test/SDL_Test/Assets/gfx/hello.bmp",message);
    
    
    
    cGame_Manager* game = new cGame_Manager();
    cSystem* baseSystem = game->create_system(BASE_SYSTEM);
    cRender_System* renderSystem = (cRender_System*)game->create_system(RENDER_SYSTEM);
    
    
    if( baseSystem == NULL){
        n8::log_error("Game manager wasn't initialized");
    }
    else{
        n8::log_info("Game manager was initialized");
    }
    
    if (renderSystem == NULL) {
        n8::log_error("Render system wasn't initialized");
    }
    else{
        n8::log_info("Render system was initialized");
    }
    
    cEntity* nate = game->register_entity(game->create_user_entity(n8::get_next_id(), "Nate", 0, 0, sprite));
    game->register_entity(game->create_user_entity(n8::get_next_id(), "Megan", 0, 0, sprite));
    
    cEntity* test = new cEntity(n8::get_next_id());
    test->add_component(new cPosition_Component(POSITION, 0, 0));
    game->register_entity(test);
    
    
    
    
    
    
    //Apply the background to the screen
    apply_surface( 0, 0, background, screen );
    apply_surface( 320, 0, background, screen );
    apply_surface( 0, 240, background, screen );
    apply_surface( 320, 240, background, screen );
    
    
    //Apply the message to the screen
    apply_surface( 180, 140, ((cDrawable_Component*)nate->get_component(DRAWABLE))->get_sprite()->get_sprite(), screen );
    
    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {
        return 1;    
    }
    
    //Show window until the user clicks 'exit'
    bool running = true;
    //The timer starting time
    Uint32 start = 0;
    
    SDL_Event event;
    while (running) {
        
        start = SDL_GetTicks();
        
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            else if( event.type == SDL_KEYDOWN )
            { 
                switch( event.key.keysym.sym )
                {}
            }
            else if( event.type == SDL_MOUSEBUTTONDOWN )
            {}
            else if( event.type == SDL_MOUSEBUTTONUP )
            {}
        }
        
        cout << "Game Logic" << endl;
        game->get_system(BASE_SYSTEM)->update();
        //game->get_system(COLLISION_SYSTEM)->update();
        //game->get_system(INTERACTION_SYSTEM)->update();
        game->get_system(RENDER_SYSTEM)->update();
        
        cout << endl;
    }
    
    //Free the surfaces
    SDL_FreeSurface( message );
    SDL_FreeSurface( background );
    
    //Quit SDL
    SDL_Quit();
    
    //Return
    return 0;
}

SDL_Surface *load_image( std::string filename ) 
{
    //Temporary storage for the image that's loaded
    SDL_Surface* loadedImage = NULL;
    
    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;
    
    //Load the image
    loadedImage = SDL_LoadBMP( filename.c_str() );
    
    //If nothing went wrong in loading the image
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );
        
        //Free the old image
        SDL_FreeSurface( loadedImage );
    }
    
    //Return the optimized image
    return optimizedImage;
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
