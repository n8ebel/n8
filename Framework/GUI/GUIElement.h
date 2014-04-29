/*
 * GUIElement.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            4/20/14
 * Organization:    n8Tech
 *
 */

#ifndef GUI_ELEMENT_H
#define GUI_ELEMENT_H

#include <iostream>

#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "SDL2_ttf/SDL_ttf.h"

#include "Window.h"
#include "Rectangle.h"
#include "LTexture.h"
#include "Font.h"
#include "Color.h"
#include "Style.h"

namespace gui {
    
class GUIElement{
    public:
        GUIElement();
        GUIElement(int p_x, int p_y, int p_w, int p_h);
        virtual ~GUIElement();
    
        virtual void Build(){m_built = true;}
        virtual void Draw(n8::Window*) = 0;
        virtual bool CheckMouseClickDown(int p_x, int p_y) = 0;
        virtual bool CheckMouseClickUp(int p_x, int p_y) = 0;
        virtual bool CheckMouseMove() = 0;
        virtual bool Update(Uint32 p_currentTime) = 0;
        
        virtual void OffsetPosition(int p_x, int p_y);
    
        void SetStyle(Style* p_style);
    
        Style* GetStyle()const{return m_style;}
    protected:
        Style* m_style;
        n8::Rectangle m_rectangle;
        SDL_Texture* m_texture;
    
        bool m_built;
    
        int m_x;
        int m_y;
        int m_h;
        int m_w;
        
        bool m_hasFocus;
    };
}

#endif /* defined(GUI_ELEMENT_H) */
