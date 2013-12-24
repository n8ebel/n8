//
//  main.cpp
//  goobar
//
//  Created by Nate Ebel on 12/22/13.
//  Copyright (c) 2013 n8Tech. All rights reserved.
//

#include "SDL/SDL.h"

#include "GameManager.h"
#include "MenuState.h"
#include "GameState.h"

#include <iostream>

using namespace std;



int main(int argc, char* argv[]){
    SDL_Init( SDL_INIT_EVERYTHING );
    
    GameManager* game = GameManager::getGameManager();
    
    game->setCaption("n8");
    
    game->registerState(0, new MenuState());
    game->registerState(1, new GameState());
    
    game->startGame();
    
    game->endGame();
    
    
    
    
    SDL_Quit();
    return 0;
}
