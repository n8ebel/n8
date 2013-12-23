//
//  GamaManager.cpp
//  goobar
//
//  Created by Nate Ebel on 12/22/13.
//  Copyright (c) 2013 n8Tech. All rights reserved.
//

#include "GameManager.h"
#include "MenuState.h"

GameManager::GameManager(){
    fps = 60;
    background = SDL_SetVideoMode(400, 400, 32, SDL_SWSURFACE);
    SDL_WM_SetCaption( "n8", NULL );
    
    stateManager = new State_Manager(new State(), new MenuState());
}

GameManager::~GameManager(){
    
}

void GameManager::start(){
    bool quit = false;
    SDL_Event event;
    
    while (quit == false) {
        while( SDL_PollEvent( &event ) )
        {
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                stateManager->currentState++;
            }
            else{
                
                currentTime = SDL_GetTicks();
                
                stateManager->states[stateManager->currentState%2]->update(currentTime);
                stateManager->states[stateManager->currentState%2]->render(background);
                
                
                if ( 1000/fps > SDL_GetTicks() - currentTime) {
                    SDL_Delay(1000/fps - (SDL_GetTicks() - currentTime));
                }
            }
        
        
        }
    }
    
}