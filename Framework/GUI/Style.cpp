/*
 * Style.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            4/28/14
 * Organization:    n8Tech
 *
 */

#include "Style.h"

namespace gui {
    
    Style::Style(n8::Window* p_window, n8::Font* p_font) :  m_window(p_window),
                                                            m_font(p_font)
    
    {
        m_containerColor.Set(50, 50, 50);
        m_buttonColor.Set(100, 100, 255);
        m_hoverColor.Set(20, 20, 190);
        m_pressedColor.Set(190, 175, 20);
        
        m_fontColor.Set(0, 0, 0);
        
        m_focusColor.Set(0, 50, 2550);
        m_inputBackgroundColor.Set(255, 255, 255);
        m_cursorColor.Set(0, 0, 0);
        
        m_defaultColor.Set(255, 255, 255);
        
    }
    
    Style::~Style(){
        
    }
    
    void Style::SetFont(n8::Font* p_font){
        
    }
    
    n8::Window* Style::GetWindow(){
        return m_window;
    }
    
    n8::Font* Style::GetFont() const{
        return m_font;
    }
    
    void Style::SetColor(EStyleColor p_color, int p_r, int p_g, int p_b){
        SetColor(p_color, p_r, p_g, p_b, DEFAULT_ALPHA);
    }
    
    void Style::SetColor(EStyleColor p_color, int p_r, int p_g, int p_b, int p_a){
        if (p_color == EStyleColor::Button) {
            m_buttonColor.Set(p_r, p_g, p_b,p_a);
        }
        else if(p_color == EStyleColor::Container){
            m_containerColor.Set(p_r, p_g, p_b,p_a);
        }
        else if(p_color == EStyleColor::Focus){
            m_focusColor.Set(p_r, p_g, p_b,p_a);
        }
        else if(p_color == EStyleColor::Font){
            m_fontColor.Set(p_r, p_g, p_b,p_a);
        }
        else if(p_color == EStyleColor::Hover){
            m_hoverColor.Set(p_r, p_g, p_b,p_a);
        }
        else if(p_color == EStyleColor::InputBackground){
            m_inputBackgroundColor.Set(p_r, p_g, p_b,p_a);
        }
        else if(p_color == EStyleColor::Pressed){
            m_pressedColor.Set(p_r, p_g, p_b,p_a);
        }
        else if(p_color == EStyleColor::Cursor){
            m_cursorColor.Set(p_r,p_g,p_b,p_a);
        }
    }
    
    n8::Color Style::GetColor(EStyleColor p_color){
        if (p_color == EStyleColor::Button) {
            return m_buttonColor;
        }
        else if(p_color == EStyleColor::Container){
            return m_containerColor;
        }
        else if(p_color == EStyleColor::Focus){
            return m_focusColor;
        }
        else if(p_color == EStyleColor::Font){
            return m_fontColor;
        }
        else if(p_color == EStyleColor::Hover){
            return m_hoverColor;
        }
        else if(p_color == EStyleColor::InputBackground){
            return m_inputBackgroundColor;
        }
        else if(p_color == EStyleColor::Pressed){
            return m_pressedColor;
        }
        else if(p_color == EStyleColor::Cursor){
            return m_cursorColor;
        }
        else{
            return m_defaultColor;
        }
    }
    
}