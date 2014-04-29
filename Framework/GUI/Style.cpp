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
        m_containerColor.Set(50, 50, 50,255);
        m_buttonColor.Set(0, 0, 255,255);
        m_fontColor.Set(0, 0, 0, 255);
        m_focusColor.Set(0, 255, 0, 255);
        m_pressedColor.Set(150, 150, 150,255);
    }
    
    Style::~Style(){
        
    }
    
    void Style::SetFont(n8::Font* p_font){
        
    }
    
    void Style::SetContainerColor(int p_r, int p_g, int p_b){
        m_containerColor.Set(p_r, p_g, p_b);
    }
    void Style::SetContainerColor(int p_r, int p_g, int p_b, int p_a){
        m_containerColor.Set(p_r, p_g, p_b, p_a);
    }
    void Style::SetButtonColor(int p_r, int p_g, int p_b){
        m_buttonColor.Set(p_r, p_g, p_b);
    }
    void Style::SetButtonColor(int p_r, int p_g, int p_b, int p_a){
        m_buttonColor.Set(p_r, p_g, p_b, p_a);
    }
    void Style::SetFontColor(int p_r, int p_g, int p_b){
        m_fontColor.Set(p_r, p_g, p_b);
    }
    void Style::SetFontColor(int p_r, int p_g, int p_b, int p_a){
        m_fontColor.Set(p_r, p_g, p_b, p_a);
    }
    void Style::SetFocusColor(int p_r, int p_g, int p_b){
        m_focusColor.Set(p_r, p_g, p_b);
    }
    void Style::SetFocusColor(int p_r, int p_g, int p_b, int p_a){
        m_focusColor.Set(p_r, p_g, p_b, p_a);
    }
    void Style::SetPressedColor(int p_r, int p_g, int p_b){
        m_pressedColor.Set(p_r, p_g, p_b);
    }
    void Style::SetPressedColor(int p_r, int p_g, int p_b, int p_a){
        m_pressedColor.Set(p_r, p_g, p_b, p_a);
    }
    
    n8::Window* Style::GetWindow(){
        return m_window;
    }
    
    n8::Font* Style::GetFont() const{
        return m_font;
    }
    
    n8::Color Style::GetContainerColor() const{
        return m_containerColor;
    }
    n8::Color Style::GetButtonColor() const{
        return m_buttonColor;
    }
    n8::Color Style::GetFontColor() const{
        return m_fontColor;
    }
    n8::Color Style::GetFocusColor() const{
        return m_containerColor;
    }
    n8::Color Style::GetPressedColor() const{
        return m_containerColor;
    }
    
}