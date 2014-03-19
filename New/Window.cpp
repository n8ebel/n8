/*
 *  Window.cpp
 *  goobar
 *
 *  Created by Nate Ebel on 3/18/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#include <assert.h>

#include "Window.h"
#include "ServiceManager.h"
#include "Log.h"

n8::Window::Window(){
    m_background = NULL;
    ResizeWindow(DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT);
}

n8::Window::~Window(){
    
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
void n8::Window::ResizeWindow(int w, int h){
    m_screenWidth = w;
    m_screenHeight = h;
    
    if(m_background != NULL){
        SDL_FreeSurface(m_background);
    }
    
    m_background = SDL_SetVideoMode(m_screenWidth, m_screenHeight, DEFAULT_BPP, SDL_SWSURFACE );
    assert(m_background);
}

/**
 *  @return a pointer to the background surface
 */
SDL_Surface* n8::Window::GetSurface(){
    assert(m_background);
    return m_background;
}

/** Sets the window caption */
void n8::Window::SetCaption(char* caption){
    SDL_WM_SetCaption( caption, NULL );
}