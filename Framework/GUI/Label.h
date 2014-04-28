/*
 * Label.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            4/27/14
 * Organization:    n8Tech
 *
 */

#ifndef LABEL_H
#define LABEL_H

#include <iostream>

#include "GUIElement.h"

#include "Window.h"
#include "LTexture.h"
#include "Font.h"
#include "Log.h"

namespace gui {
    
class Label : public GUIElement{
    public:
    
        enum class EColor{Black,White};
    
        Label(std::string p_text, n8::Font* p_font, EColor p_color, const n8::Window* p_window, int p_x, int p_y);
        ~Label();
        
        virtual void Draw(n8::Window*) override;
        virtual bool CheckMouseClickDown(int p_x, int p_y)override;
        virtual bool CheckMouseClickUp(int p_x, int p_y)override;
        virtual bool CheckMouseMove()override;
        virtual bool Update(Uint32 p_currentTime)override;
        
        void OffsetPosition(int p_x, int p_y) override;
    protected:
        const unsigned M_TEXT_OFFSET_Y = 10;
    
        SDL_Rect m_shape;
        SDL_Texture* m_texture;
        SDL_Color m_textColor;
        LTexture m_textTexture;
    
        std::string m_labelText;
        int m_x;
        int m_y;
        int m_h;
        int m_w;
        
        bool m_hasFocus;
    };
}

#endif /* defined(LABEL_H) */
