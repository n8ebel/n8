//
//  GamaManager.cpp
//  goobar
//
//  Created by Nate Ebel on 12/22/13.
//  Copyright (c) 2013 n8Tech. All rights reserved.
//

#include "GameManager.h"
#include "InputManager.h"

GameManager* GameManager::GameManager_Instance_ = NULL;

GameManager* GameManager::getGameManager(){
    if(GameManager_Instance_ == NULL) {
        GameManager_Instance_ = new GameManager();
    }
    
    return GameManager_Instance_;
}

GameManager::GameManager(){
    fps_ = DEFAULT_FPS;
    background_ = NULL;
    resizeScreenSurface(DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT, DEFAULT_BPP);
    
    stateManager_ = State_Manager::getInstance();
}

GameManager::~GameManager(){
    SDL_FreeSurface(background_);
    delete stateManager_;
}

void GameManager::startGame(){
    bool quit = false;
    
    stateManager_->processState(currentTime_, background_);
    
    
    
    while (quit == false) {
        
                
        currentTime_ = SDL_GetTicks();
        
       // InputManager::getInstance()->handle_input();
        stateManager_->processState(currentTime_, background_);
        
        
        if ( 1000/fps_ > SDL_GetTicks() - currentTime_) {
            SDL_Delay(1000/fps_ - (SDL_GetTicks() - currentTime_));
        }
        
        
        
        }
    
    
}


void GameManager::endGame(){
    
}

bool GameManager::registerState(int identifier, State* state){
    return stateManager_->registerState(identifier, state);
    
}

int GameManager::setFPS(int newFPS){
    if(newFPS > 0){
        fps_ = newFPS;
    }
    
    return fps_;
}

void GameManager::resizeScreenSurface(int w, int h, int bpp){
    screenWidth_ = w;
    screenHeight_ = h;
    
    if(background_ != NULL){
        SDL_FreeSurface(background_);
    }
    
    background_ = SDL_SetVideoMode(screenWidth_, screenHeight_, bpp, SDL_SWSURFACE);
}

SDL_Surface* GameManager::getScreenSurface(){
    return background_;
}

void GameManager::setCaption(char* caption){
    SDL_WM_SetCaption( caption, NULL );
}