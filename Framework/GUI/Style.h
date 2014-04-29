/*
 * Style.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            4/28/14
 * Organization:    n8Tech
 *
 */

#ifndef STYLE_H
#define STYLE_H

#include <iostream>

#include "Font.h"
#include "Color.h"
#include "Window.h"

namespace gui {
    class Style{
    public:
        Style(n8::Window* p_window, n8::Font* p_font);
        ~Style();
        
        void SetFont(n8::Font* p_font);
        
        void SetContainerColor(int p_r, int p_g, int p_b);
        void SetContainerColor(int p_r, int p_g, int p_b, int p_a);
        
        void SetButtonColor(int p_r, int p_g, int p_b);
        void SetButtonColor(int p_r, int p_g, int p_b, int p_a);
        
        void SetFontColor(int p_r, int p_g, int p_b);
        void SetFontColor(int p_r, int p_g, int p_b, int p_a);
        
        void SetFocusColor(int p_r, int p_g, int p_b);
        void SetFocusColor(int p_r, int p_g, int p_b, int p_a);
        
        void SetPressedColor(int p_r, int p_g, int p_b);
        void SetPressedColor(int p_r, int p_g, int p_b, int p_a);
        
        n8::Window* GetWindow();
        n8::Font* GetFont() const;
        n8::Color GetContainerColor() const;
        n8::Color GetButtonColor() const;
        n8::Color GetFontColor() const;
        n8::Color GetFocusColor() const;
        n8::Color GetPressedColor() const;
    
    private:
        n8::Window* m_window;
        
        n8::Font* m_font;
        n8::Color m_containerColor;
        n8::Color m_buttonColor;
        n8::Color m_fontColor;
        n8::Color m_focusColor;
        n8::Color m_pressedColor;
    };
}


#endif /* defined(STYLE_H) */
