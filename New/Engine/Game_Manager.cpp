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
int Game_Manager::nextid_ = 0;  //static counter for unique ids

/** Singleton access method
 *
 *  @return Pointer to the Game_Manager instance
 */
Game_Manager* Game_Manager::get_instance(){
    if(instance_ == NULL) {
        instance_ = new Game_Manager();
    }
    
    return instance_;
}

/** Default constructor
 *
 *  Initializes all values and resizes the screen to the
 *      default values
 *
 */
Game_Manager::Game_Manager(){
    fps_ = DEFAULT_FPS;
    quit_ = false;
    background_ = NULL;
    resize_screen_surface(DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT, DEFAULT_BPP);
}

/** Default destructor
 *
 *  Frees the background surface
 */
Game_Manager::~Game_Manager(){
    if (DEBUGGING) {
        Log::info(GAME_MANAGER, "Destructor was called");
    }
    SDL_FreeSurface(background_);
}

/** Runs the game loop for the engine
 *
 *  Uses the quit_ flag to determine when to exit the loop
 *  Each iteration through the loop processes the current state
 */
void Game_Manager::run_game(){
    
    while (quit_ == false) {
        currentTime_ = SDL_GetTicks();
        
        State_Manager::get_instance()->process_state(currentTime_, background_);
        
        if (State_Manager::get_instance()->get_stack_size() == 0) {
            end_game();
        }
        
        if ( 1000/fps_ > SDL_GetTicks() - currentTime_) {
            SDL_Delay(1000/fps_ - (SDL_GetTicks() - currentTime_));
        }
    }

}

/** handles any operations specific to ending the game */
void Game_Manager::end_game(){
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

/** Changes the frame per second value for the game loop
 *
 *  @param newFPS The integer value for the fps value
 *
 *  @return The fps value
 */
int Game_Manager::set_fps(int newFPS){
    if(newFPS > 0){
        fps_ = newFPS;
    }
    
    return fps_;
}

/** Resizes the screen to the specified dimensions
 *  
 *  First the existing screen surface is freed, then
 *      a new surface is created with the specified
 *      dimensions
 *
 *  @param w The integer width of the screen
 *  @param h The integer height of the screen
 *  @param bpp The bitmap depth
 */
void Game_Manager::resize_screen_surface(int w, int h, int bpp){
    screenWidth_ = w;
    screenHeight_ = h;
    
    if(background_ != NULL){
        SDL_FreeSurface(background_);
    }
    
    background_ = SDL_SetVideoMode(screenWidth_, screenHeight_, bpp, SDL_SWSURFACE);
}

/**
 *  @return a pointer to the background surface
 */
SDL_Surface* Game_Manager::get_screen_surface(){
    return background_;
}

/** Sets the window caption */
void Game_Manager::set_caption(char* caption){
    SDL_WM_SetCaption( caption, NULL );
}