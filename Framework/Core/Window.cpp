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

#define TAG "Window"

n8::Window::Window(){
    m_screenSurface = NULL;
    m_screenRenderer = NULL;
    m_window = NULL;
    ResizeWindow(DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT);
}

n8::Window::~Window(){
    
    if(m_window){
        SDL_DestroyWindow(m_window);
        m_window = NULL;
    }
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
    
    // create a window
    
    m_window = SDL_CreateWindow(
                                           
                                           "SDL 2 window",             // window title
                                           
                                           SDL_WINDOWPOS_CENTERED,     // x position, centered
                                           
                                           SDL_WINDOWPOS_CENTERED,     // y position, centered
                                           
                                           m_screenWidth,                        // width, in pixels
                                           
                                           m_screenHeight,                        // height, in pixels
                                           
                                           0           // flags
                                           
           
                                );
    if( m_window == NULL )
    {
        std::string msg("Window could not be created: SDL Error: %s\n", SDL_GetError() );
        Log::Error(TAG, msg);
        assert(m_window);
    }
    
    m_screenSurface = SDL_GetWindowSurface(m_window);
    if( m_screenSurface == NULL )
    {
        std::string msg("Could not get screen surface: SDL Error: %s\n", SDL_GetError() );
        Log::Error(TAG, msg);
        assert(m_screenSurface);
    }
    
    m_screenRenderer = SDL_GetRenderer(m_window);
    if( m_screenRenderer == NULL )
    {
        std::string msg("Could not get renderer: SDL Error: %s\n", SDL_GetError() );
        Log::Error(TAG, msg);
        assert(m_screenRenderer);
    }
    else{
        //Initialize renderer color
        SDL_SetRenderDrawColor( m_screenRenderer, m_rendererR, m_rendererG, m_rendererB, m_renererA );
    }
    
    

}

/**
 *  @return a pointer to the background surface
 */
SDL_Surface* n8::Window::GetSurface() const{
    assert(m_window);
    return m_screenSurface;
}

SDL_Renderer* n8::Window::GetRenderer() const{
    assert(m_screenRenderer);
    return m_screenRenderer;
}

SDL_Window* n8::Window::GetWindow() const{
    assert(m_window);
    return m_window;
}

/** Sets the window caption */
void n8::Window::SetTitle(char* caption){
    SDL_SetWindowTitle(m_window, caption);
}