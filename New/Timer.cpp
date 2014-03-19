/*
 *  Timer.cpp
 *  goobar
 *
 *  Created by Nate Ebel on 3/18/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#include "Timer.h"

n8::Timer::Timer(){
    m_currentTime = SDL_GetTicks();
}

n8::Timer::~Timer(){
    
}

void n8::Timer::UpdateCurrentTime(){
    m_currentTime = SDL_GetTicks();
}

void n8::Timer::SyncGame(unsigned fps){
    if ( 1000/fps > SDL_GetTicks() - m_currentTime) {
        SDL_Delay(1000/fps - (SDL_GetTicks() - m_currentTime));
    }
    m_currentTime=SDL_GetTicks();
}