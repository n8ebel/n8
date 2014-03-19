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

#include "SDL/SDL.h"
#include "SDL_image/SDL_image.h"

namespace n8{
    
class Window{
public:
    static const int DEFAULT_SCREEN_WIDTH = 400;
    static const int DEFAULT_SCREEN_HEIGHT = 400;
    static const int DEFAULT_BPP= 32;
    
    Window();
    ~Window();
    
    void SetCaption(char* caption);
    void ResizeWindow(int w, int h);
    SDL_Surface* GetSurface();
    
private:
    
    unsigned m_screenWidth;  /** < width of the screen surface **/
    unsigned m_screenHeight; /** < height of the screen surface **/
    SDL_Surface* m_background;  /** < surface to render things to **/
    
    
};

}

#endif /* defined(WINDOW_H) */
