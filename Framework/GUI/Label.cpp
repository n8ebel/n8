/*
 * Label.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            4/27/14
 * Organization:    n8Tech
 *
 */

#include "Label.h"


gui::Label::Label(std::string p_text, n8::Font* p_font, EColor p_color, const n8::Window* p_window, int p_x, int p_y) : GUIElement() {
    m_labelText = p_text;
    
    m_texture = nullptr;
    m_x = p_x;
    m_y = p_y;
    
    if (p_color == EColor::Black) {
        m_textColor.Set(0,0,0,255);
    }
    else{
        m_textColor.Set(255, 255, 255,255);
    }
    
    m_textTexture.loadFromRenderedText( p_window->GetRenderer(), p_font->GetFont(), m_labelText.c_str(), (*m_textColor.GetColor()) );
        
}

gui::Label::~Label(){
    
}

void gui::Label::Draw(n8::Window* p_window){
    m_textTexture.render(p_window->GetRenderer(), m_x, m_y);
}

bool gui::Label::CheckMouseClickDown(int p_x, int p_y){
    return false;
}
bool gui::Label::CheckMouseClickUp(int p_x, int p_y){
    return false;
}
bool gui::Label::CheckMouseMove(){
    return false;
}
bool gui::Label::Update(Uint32 p_currentTime){
    return false;
}

void gui::Label::OffsetPosition(int p_x, int p_y){
    m_x += p_x;
    m_y += p_y;
}