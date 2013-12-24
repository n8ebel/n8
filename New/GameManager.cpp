/*
 * GameManager.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            12/22/13
 * Organization:    n8Tech
 *
 */
#include <iostream>

#include "GameManager.h"
#include "InputManager.h"
#include "Log.h"
#include "n8.h"

using namespace std;



GameManager* GameManager::GameManager_Instance_ = NULL;

GameManager* GameManager::getGameManager(){
    if(GameManager_Instance_ == NULL) {
        GameManager_Instance_ = new GameManager();
    }
    
    return GameManager_Instance_;
}

GameManager::GameManager(){
    fps_ = DEFAULT_FPS;
    quit_ = false;
    background_ = NULL;
    resizeScreenSurface(DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT, DEFAULT_BPP);
    
    stateManager_ = State_Manager::getInstance();
}

GameManager::~GameManager(){
    SDL_FreeSurface(background_);
    delete stateManager_;
}

void GameManager::startGame(){
    
    stateManager_->processState(currentTime_, background_);
    
    
    
    while (quit_ == false) {
        
                
        currentTime_ = SDL_GetTicks();
        
       // InputManager::getInstance()->handle_input();
        stateManager_->processState(currentTime_, background_);
        
        if (State_Manager::getInstance()->getStackSize() == 0) {
            endGame();
        }
        
        if ( 1000/fps_ > SDL_GetTicks() - currentTime_) {
            SDL_Delay(1000/fps_ - (SDL_GetTicks() - currentTime_));
        }
        
        
        
    }
    
    
}


void GameManager::endGame(){
    quit_ = true;
    
    Log::info(GAME_MANAGER, "Ending Game");
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