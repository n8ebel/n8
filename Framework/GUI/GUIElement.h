//
//  GUIElement.h
//  DevApp
//
//  Created by Nate Ebel on 4/21/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#ifndef __DevApp__GUIElement__
#define __DevApp__GUIElement__

#include <iostream>

#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "SDL2_ttf/SDL_ttf.h"

#include "Window.h"

namespace gui {
    
class GUIElement{
    public:
        GUIElement(int p_x, int p_y, int p_w, int p_h);
        virtual ~GUIElement();
        
        virtual void Draw(n8::Window*) = 0;
        virtual bool CheckMouseClickDown(int p_x, int p_y) = 0;
        virtual bool CheckMouseClickUp(int p_x, int p_y) = 0;
        virtual bool CheckMouseMove() = 0;
        virtual bool Update(Uint32 p_currentTime) = 0;
        
        void OffsetPosition(int p_x, int p_y);
    protected:
        SDL_Rect m_shape;
        SDL_Texture* m_texture;
        
        int m_x;
        int m_y;
        int m_h;
        int m_w;
        
        bool m_hasFocus;
    };
}

#endif /* defined(__DevApp__GUIElement__) */
