//
//  main.cpp
//  n8
//
//  Created by Nate Ebel on 7/26/13.
//  Copyright (c) 2013 n8Tech. All rights reserved.
//

#include "SDL/SDL.h"
#include "n8.h"
#include <iostream>

using namespace std;


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


int main( int argc, char* argv[] )
{
    // Testing of engine code
    cEntity* foo = n8::create_user_entity(n8::nextID, "Nate", 3,3);
    
    cEntity* goo = new cEntity(99);
    
    goo->add_component(new cName_Component(n8::NAME,"Goku"));
    goo->add_component(new cPosition_Component(n8::POSITION, new cPoint(5,5)));
    
    
    cout << "Name: " << n8::get_name_component(goo)->get_name() << endl;  
    cout << "X: " << n8::get_position_component(goo)->get_position()->get_x() << endl;
    
    cout << "Name: " << n8::get_name_component(foo)->get_name() << endl;  
    cout << "X: " << n8::get_position_component(foo)->get_position()->get_x() << endl;
    
    
    
    
    
    
    delete foo;
    delete goo;
    
    
    
    
    
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
    
    //Apply the background to the screen
    apply_surface( 0, 0, background, screen );
    apply_surface( 320, 0, background, screen );
    apply_surface( 0, 240, background, screen );
    apply_surface( 320, 240, background, screen );
    
    
    //Apply the message to the screen
    apply_surface( 180, 140, message, screen );
    
    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {
        return 1;    
    }
    
    //Show window until the user clicks 'exit'
    bool running = true;
    
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }
    }
    
    //Free the surfaces
    SDL_FreeSurface( message );
    SDL_FreeSurface( background );
    
    //Quit SDL
    SDL_Quit();
    
    //Return
    return 0;
}
