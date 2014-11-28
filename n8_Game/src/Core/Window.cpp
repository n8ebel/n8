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

/** Constructor 
 *  Creates SDL window, gets pointers to screen surface and renderer, and sets inital drawing render color
 */
n8::Window::Window(){
    ResizeWindow(DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT);
}

/** Destructor
 *  Destroys SDL window object
 */
n8::Window::~Window(){ }

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
    
    m_window = std::unique_ptr<SDL_Window, SDL_Window_Deleter>(
    
    
                                         SDL_CreateWindow(
                                                          
                                                          "SDL 2 window",             // window title
                                                          
                                                          SDL_WINDOWPOS_CENTERED,     // x position, centered
                                                          
                                                          SDL_WINDOWPOS_CENTERED,     // y position, centered
                                                          
                                                          m_screenWidth,                        // width, in pixels
                                                          
                                                          m_screenHeight,                        // height, in pixels
                                                          
                                                          0           // flags
                                                          
                                                          
                                                          ));
    
    if( m_window == nullptr )
    {
        std::string msg("Window could not be created: SDL Error: %s\n", SDL_GetError() );
        Log::Error(TAG, msg);
        assert(m_window);
    }
    
    m_screenSurface = std::unique_ptr<SDL_Surface, SDL_Screen_Surface_Deleter>(SDL_GetWindowSurface(m_window.get()));
    if( m_screenSurface == nullptr )
    {
        std::string msg("Could not get screen surface: SDL Error: %s\n", SDL_GetError() );
        Log::Error(TAG, msg);
        assert(m_screenSurface);
    }
    
    m_screenRenderer = std::unique_ptr<SDL_Renderer, SDL_Renderer_Deleter>(SDL_GetRenderer(m_window.get()));
    if( m_screenRenderer == nullptr )
    {
        std::string msg("Could not get renderer: SDL Error: %s\n", SDL_GetError() );
        Log::Error(TAG, msg);
        assert(m_screenRenderer);
    }
    else{
        //Initialize renderer color
        SDL_SetRenderDrawColor( m_screenRenderer.get(), m_rendererR, m_rendererG, m_rendererB, m_renererA );
    }
    
    

}

/** Gets a pointer to the window surface
 *
 *  @return a pointer to the window surface
 */
const SDL_Surface& n8::Window::GetSurface() const{
    return *m_screenSurface;
}

/** Gets a pointer to the window renderer
 *
 *  @return Pointer to the screen renderer
 */
const SDL_Renderer& n8::Window::GetRenderer() const{
    return *m_screenRenderer;
}

/** Gets a pointer to the window object
 *
 *  @return Pointer to the SDL_Window object
 */
//SDL_Window* n8::Window::GetWindow() const{
//    assert(m_window);
//    return m_window.get();
//}

const SDL_Window& n8::Window::GetWindow() const{
    return *m_window;
}


/** Sets the window caption 
 *
 *  @param p_caption Text for window title
 */
void n8::Window::SetTitle(char* p_caption){
    SDL_SetWindowTitle(m_window.get(), p_caption);
}