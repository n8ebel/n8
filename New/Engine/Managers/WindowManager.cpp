//
//  WindowManager.cpp
//  goobar
//
//  Created by Nate Ebel on 1/15/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#include "WindowManager.h"

WindowManager::WindowManager(){
    m_background = NULL;
    ResizeScreenSurface(DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT, DEFAULT_BPP);
}

WindowManager::~WindowManager(){
    assert(m_background);
    SDL_FreeSurface(m_background);
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
void WindowManager::ResizeScreenSurface(int w, int h, int bpp){
    m_screenWidth = w;
    m_screenHeight = h;
    
    if(m_background != NULL){
        SDL_FreeSurface(m_background);
    }
    
    m_background = SDL_SetVideoMode(m_screenWidth, m_screenHeight, bpp, SDL_SWSURFACE);
    assert(m_background);
}

/**
 *  @return a pointer to the background surface
 */
SDL_Surface* WindowManager::GetScreenSurface(){
    assert(m_background);
    return m_background;
}

/** Sets the window caption */
void WindowManager::SetCaption(char* caption){
    SDL_WM_SetCaption( caption, NULL );
}