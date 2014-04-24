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

#include "Window.h"

namespace gui {
    class GUIElement{
    public:
        GUIElement();
        virtual ~GUIElement();
        
        virtual void Draw(n8::Window*) = 0;
        virtual bool CheckMouseClickDown(int p_x, int p_y) = 0;
        virtual bool CheckMouseClickUp(int p_x, int p_y) = 0;
        virtual bool CheckMouseMove() = 0;
        
        void OffsetPosition(int p_x, int p_y);
    protected:
        SDL_Texture* m_texture;
        
        int m_x;
        int m_y;
        int m_h;
        int m_w;
        
        SDL_Rect m_shape;
    };
}

#endif /* defined(__DevApp__GUIElement__) */
