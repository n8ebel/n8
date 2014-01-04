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

#include "Game_Manager.h"
#include "State_Manager.h"


using namespace std;

Game_Manager* Game_Manager::instance_ = NULL;  //Static singleton instance initialzation
int Game_Manager::nextid_ = 0;

Game_Manager* Game_Manager::getInstance(){
    if(instance_ == NULL) {
        instance_ = new Game_Manager();
    }
    
    return instance_;
}

Game_Manager::Game_Manager(){
    fps_ = DEFAULT_FPS;
    quit_ = false;
    background_ = NULL;
    resizeScreenSurface(DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT, DEFAULT_BPP);
}

Game_Manager::~Game_Manager(){
    if (DEBUGGING) {
        Log::info(GAME_MANAGER, "Destructor was called");
    }
    SDL_FreeSurface(background_);
}

void Game_Manager::startGame(){
    
    while (quit_ == false) {
        currentTime_ = SDL_GetTicks();
        
       // InputManager::getInstance()->handle_input();
        State_Manager::getInstance()->processState(currentTime_, background_);
        
        if (State_Manager::getInstance()->getStackSize() == 0) {
            endGame();
        }
        
        if ( 1000/fps_ > SDL_GetTicks() - currentTime_) {
            SDL_Delay(1000/fps_ - (SDL_GetTicks() - currentTime_));
        }
        
        
        
    }
    
    
}


void Game_Manager::endGame(){
    quit_ = true;
    
    Log::info(GAME_MANAGER, "Ending Game");
}

/** Used to get the next available unique integer id for a created entity.  When called nextid_ is incremented so the return values are always unique.
 *
 *  @return The next available id number
 */
int Game_Manager::get_next_id(){
    nextid_++;
    return nextid_;
}



int Game_Manager::setFPS(int newFPS){
    if(newFPS > 0){
        fps_ = newFPS;
    }
    
    return fps_;
}

void Game_Manager::resizeScreenSurface(int w, int h, int bpp){
    screenWidth_ = w;
    screenHeight_ = h;
    
    if(background_ != NULL){
        SDL_FreeSurface(background_);
    }
    
    background_ = SDL_SetVideoMode(screenWidth_, screenHeight_, bpp, SDL_SWSURFACE);
}

SDL_Surface* Game_Manager::getScreenSurface(){
    return background_;
}

void Game_Manager::setCaption(char* caption){
    SDL_WM_SetCaption( caption, NULL );
}