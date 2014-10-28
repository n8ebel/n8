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
    
    Style::Style(){
        m_font = nullptr;
    }
    
    /** Constructor.
     *  Sets default color values, and stores pointers to the game window
     *  and a font resources.
     */
    Style::Style(std::string fontFilepath) :  m_fontFilepath(fontFilepath)
    
    {
        m_font = nullptr;
        m_containerColor.Set(175, 150, 175);
        m_buttonColor.Set(50, 50, 50);
        m_hoverColor.Set(150, 150, 150, 100);
        m_pressedColor.Set(190, 175, 20);
        m_selectedColor.Set(50,50,200);
        
        m_fontColor.Set(0, 0, 0);
        m_hintColor.Set(160, 160, 160,100);
        
        m_focusColor.Set(0, 50, 255);
        m_inputBackgroundColor.Set(255, 255, 255);
        m_cursorColor.Set(0, 0, 0);
        
        m_defaultColor.Set(0, 0, 0);
        
    }
    
    /** Destructor */
    Style::~Style(){
        
    }
    
    Style& Style::operator=( const Style& other ){
        m_font = other.m_font;
        m_fontFilepath = other.m_fontFilepath;
        
        m_containerColor = other.m_containerColor;
        m_buttonColor = other.m_buttonColor;
        m_hoverColor = other.m_hoverColor;
        m_pressedColor = other.m_pressedColor;
        m_selectedColor = other.m_selectedColor;
        
        m_fontColor = other.m_fontColor;
        m_hintColor = other.m_hintColor;
        
        m_focusColor = other.m_focusColor;
        m_inputBackgroundColor = other.m_inputBackgroundColor;
        m_cursorColor = other.m_cursorColor;
        
        m_defaultColor = other.m_defaultColor;
        
        return *this;
    }
    
    /** Sets the font pointer.
     *
     *  @param p_font The pointer to the new font
     */
    void Style::SetFont(n8::Font* p_font){
        m_font = p_font;
    }
    
    /** Returns a pointer to the font resource
     *
     *  @return m_font Pointer to the font resource
     */
//    n8::Font* Style::GetFont() const{
//        return m_font;
//    }
    
    /** Sets a style color using the specified values and a default Alpha
     *  value.
     *
     *  @param p_color An enum defined style thats color will be changed
     *  @param p_r The new red value of the specified color
     *  @param p_g The new green value of the specified color
     *  @param p_b The new blue value of the specified color
     */
    void Style::SetColor(EStyleColor p_color, int p_r, int p_g, int p_b){
        SetColor(p_color, p_r, p_g, p_b, DEFAULT_ALPHA);
    }
    
    /** Sets a style color using the specified values      
     *
     *  @param p_color An enum defined style thats color will be changed
     *  @param p_r The new red value of the specified color
     *  @param p_g The new green value of the specified color
     *  @param p_b The new blue value of the specified color
     *  @param p_a The new alpha value of the specified color
     */
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
        else if(p_color == EStyleColor::Hint){
            m_hintColor.Set(p_r, p_g, p_b,p_a);
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
        else if(p_color == EStyleColor::Selected){
            m_selectedColor.Set(p_r,p_g,p_b,p_a);
        }
    }
    
    /** Returns the specified style color object.
     *
     *  @param p_color The enum defined style whose color should be returned
     *
     *  @return The specified color if it is valid, or a default color
     */
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
        else if(p_color == EStyleColor::Hint){
            return m_hintColor;
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
        else if(p_color == EStyleColor::Selected){
            return m_selectedColor;
        }
        else{
            return m_defaultColor;
        }
    }
    
}