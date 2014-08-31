/*
 *  Timer.cpp
 *  goobar
 *
 *  Created by Nate Ebel on 3/18/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#include "Timer.h"

/** Constructor
 *  Initializes member variables
 */
n8::Timer::Timer(){
    m_startTime = SDL_GetTicks();
    m_currentTime = SDL_GetTicks();
}

/** Destructor */
n8::Timer::~Timer(){
    
}

/** Updates the current time by polling SDL */
void n8::Timer::UpdateCurrentTime(){
    m_currentTime = SDL_GetTicks();
}

/** Ensures the game runs at the desired frame rate.
 *  Will pause the game loop if neccessary to ensure the time
 *    between game frames is equal.
 *
 *  @param p_fps The desired framerate
 */
void n8::Timer::SyncGame(unsigned p_fps){
    if ( 1000/p_fps > SDL_GetTicks() - m_currentTime) {
        SDL_Delay(1000/p_fps - (SDL_GetTicks() - m_currentTime));
    }
    m_currentTime=SDL_GetTicks();
}

/** Gets the total time, in milliseconds, since the timer was created
 *
 *  @return Milliseconds since the timer was created
 */
unsigned int n8::Timer::GetElapsedTime(){
    m_currentTime = SDL_GetTicks();
    return m_currentTime - m_startTime;
}

/** Gets the current time
 *
 *  @return The current game time
 */
unsigned int n8::Timer::GetTime(){
    return m_currentTime;
}