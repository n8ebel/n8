/*
 *  Rectangle.h
 *  goobar
 *
 *  Created by Nate Ebel on 4/28/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>

#include "SDL2/SDL.h"

namespace n8 {
    class Rectangle{
    public:
        Rectangle();
        Rectangle(int p_x, int p_y, int p_w, int p_h);
        ~Rectangle();
        
        void Resize(int p_x, int p_y, int p_w, int p_h);
        void Offset(int p_xOffset, int p_yOffset);
        int GetX();
        int GetY();
        int GetW();
        int GetH();
        SDL_Rect* GetRect();
        
    private:
        SDL_Rect m_rectangle;
    };
}

#endif /* defined(RECTANGLE_H) */
