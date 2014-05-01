/*
 * GUI.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            4/20/14
 * Organization:    n8Tech
 *
 */

#include "GUI.h"

gui::GUI::GUI(n8::Window* p_window, n8::Font* p_font) :   m_style(p_window,p_font),
                    m_hasFocus(false),
                    m_built(false)
{
    
}

gui::GUI::~GUI(){
    for (auto element : m_guiElements){
        if (element) {
            delete element;
            element = nullptr;
        }
    }
}

void gui::GUI::Build(){
    for (auto element : m_guiElements){
        element->Build();
    }
    m_built = true;
}
void gui::GUI::AddElement(gui::GUIElement* p_newWidget){
    if (p_newWidget->GetStyle() == nullptr){
        p_newWidget->SetStyle(&m_style);
    }
    m_guiElements.push_back(p_newWidget);
}

bool gui::GUI::CheckClickDown(int p_x, int p_y){
    for (int i = 0; i < m_guiElements.size(); i++) {
        if( m_guiElements[i]->CheckMouseClickDown(p_x,p_y) ){
            return true;
        }
    }
    
    return false;
}

bool gui::GUI::CheckClickUp(int p_x, int p_y){
    for (int i = 0; i < m_guiElements.size(); i++) {
        if( m_guiElements[i]->CheckMouseClickUp(p_x,p_y) ){
            return true;
        }
    }
    
    return false;
}

bool gui::GUI::CheckMove(){
    for (int i = 0; i < m_guiElements.size(); i++) {
        if( m_guiElements[i]->CheckMouseMove() ){
            return true;
        }
    }
    
    return false;
}

void gui::GUI::Draw(n8::Window* p_window){
    for (int i = 0; i < m_guiElements.size(); i++) {
        m_guiElements[i]->Draw(p_window);
    }
}

void gui::GUI::ProcessInput(SDL_Event* e){
    for(GUIElement* element : m_guiElements){
        if (dynamic_cast<InputBox*>(element) != nullptr) {
            dynamic_cast<InputBox*>(element)->HandleKeyboardInput(e);
        }
    }
}

bool gui::GUI::Update(Uint32 p_currentTime){
    m_hasFocus = false;
    for(auto element : m_guiElements){
        if(element->Update(p_currentTime)){
            m_hasFocus = true;
        }
    }
    
    return m_hasFocus;
}

bool gui::GUI::HasFocus(){
    return m_hasFocus;
}