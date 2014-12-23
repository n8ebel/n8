/*
 *  Window.h
 *  goobar
 *
 *  Created by Nate Ebel on 3/18/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>

#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"

namespace n8{
    
    struct SDL_Window_Deleter {
        void operator()(SDL_Window* window) {
            SDL_DestroyWindow(window);
        }
    };
    
    struct SDL_Screen_Surface_Deleter {
        void operator()(SDL_Surface* surface){
            
        }
    };
    
    struct SDL_Renderer_Deleter {
        void operator()(SDL_Renderer* renderer){
            
        }
    };
    
    /** \class Window
     *  \brief Represents game window.
     *
     *  Window represents and abstracts the game window.  It wraps SDL_Window.
     */
class Window{
public:
    static const int DEFAULT_SCREEN_WIDTH = 400;  /** < Default screen width in pixels */
    static const int DEFAULT_SCREEN_HEIGHT = 400; /** < Default screen height in pixels */
    static const int DEFAULT_BPP= 32; /** < Default bits per pixel */
    
    Window();
    ~Window();
    
    void SetTitle(char* caption);
    void ResizeWindow(int w, int h);
    
    const SDL_Surface& GetSurface() const;
    const SDL_Window& GetWindow() const;
    const SDL_Renderer& GetRenderer() const;
    SDL_Renderer* foobar();
    
    unsigned GetWidth() const { return m_screenWidth; }
    unsigned GetHeight() const { return m_screenHeight; }
    
private:
    
    const unsigned m_rendererR = 255; /** < Default red value for renderer draw clolor */
    const unsigned m_rendererG = 255; /** < Default green value for renderer draw color */
    const unsigned m_rendererB = 255; /** < Default blue value for renderer draw color */
    const unsigned m_renererA = 255; /** < Default alpha value for renderer draw color */
    
    unsigned m_screenWidth;  /** < width of the screen surface **/
    unsigned m_screenHeight; /** < height of the screen surface **/

    SDL_Surface* m_screenSurface;  /** < surface to render things to **/
    SDL_Renderer* m_screenRenderer; /** < The window renderer **/
    SDL_Window* m_window;
};

}

#endif /* defined(WINDOW_H) */
