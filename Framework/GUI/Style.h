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
    
    /** \class Style
     *  \brief Defines default styles for gui elements
     *
     *  Defines default color and font styles for gui elements. 
     */
    
    class Style{
    public:
        enum class EStyleColor{ Container,
                                Button,
                                Hover,
                                Focus,
                                Pressed,
                                Font,
                                Hint,
                                InputBackground,
                                Cursor,
                                Default
        };
            
        
        Style(n8::Window* p_window, n8::Font* p_font);
        ~Style();
        
        void SetFont(n8::Font* p_font);
        
        void SetColor(EStyleColor p_color, int p_r, int p_g, int p_b);
        void SetColor(EStyleColor p_color, int p_r, int p_g, int p_b, int p_a);
        
        n8::Window* GetWindow();
        n8::Font* GetFont() const;
        
        n8::Color GetColor(EStyleColor p_color);
        
    
    private:
        const Uint8 DEFAULT_ALPHA = 255;
        
        n8::Window* m_window;
        
        n8::Font* m_font;
        n8::Color m_containerColor;
        
        n8::Color m_buttonColor;
        n8::Color m_hoverColor;
        n8::Color m_pressedColor;
        
        n8::Color m_fontColor;
        n8::Color m_hintColor;
        
        n8::Color m_focusColor;
        n8::Color m_inputBackgroundColor;
        n8::Color m_cursorColor;
        
        n8::Color m_defaultColor;
        
    };
}


#endif /* defined(STYLE_H) */
