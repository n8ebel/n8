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

#define TAG "Label"


gui::Label::Label(std::string p_text, int p_x, int p_y) : GUIElement() {
    m_labelText = p_text;
    
    m_texture = nullptr;
    m_x = p_x;
    m_y = p_y;
    
}

gui::Label::~Label(){
    if (m_texture) {
        SDL_DestroyTexture(m_texture);
        m_texture = nullptr;
    }
}

void gui::Label::Build(){
    
    if (m_style) {
        m_built = m_textTexture.loadFromRenderedText(  m_style->GetWindow()->GetRenderer(), m_style->GetFont()->GetFont(), m_labelText.c_str(), m_style->GetColor(Style::EStyleColor::Font).GetColor() );
    }
    
    if (!m_built) {
        n8::Log::Error(TAG, "Label failed to build");
    }
     
}

void gui::Label::Draw(n8::Window* p_window){
   m_textTexture.render(m_style->GetWindow()->GetRenderer(), m_x, m_y);
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