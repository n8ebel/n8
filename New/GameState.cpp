//
//  GameState.cpp
//  goobar
//
//  Created by Nate Ebel on 12/23/13.
//  Copyright (c) 2013 n8Tech. All rights reserved.
//

#include "GameState.h"

#include <iostream>

using namespace std;

GameState::GameState()  {
    id_ = new ID(0);
    
}

GameState::~GameState(){
    
}

ID* GameState::getID(){
    return id_;
}

void GameState::start(){
    
}

void GameState::processInput(){
    if(InputManager::getInstance()->key_is_down(SDLK_SPACE)){
        cout << "Space was pressed" << endl;
    }
}

void GameState::update(Uint32 currentTime){
    std::cout << "GameState.update()" << std::endl;
}
void GameState::render(SDL_Surface* img){
    std::cout << "GameState.render()" << std::endl;
    SDL_FillRect(img, NULL, SDL_MapRGB(img->format, 255,0,0));
    SDL_Flip( img );
}
