//
//  main.cpp
//  goobar
//
//  Created by Nate Ebel on 12/22/13.
//  Copyright (c) 2013 n8Tech. All rights reserved.
//

#include "SDL/SDL.h"

#include "GameManager.h"
#include "State.h"

#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
    SDL_Init( SDL_INIT_EVERYTHING );
    
    GameManager* game = new GameManager();
    
    
    
    game->start();
    
    
    
    
    SDL_Quit();
    return 0;
}
