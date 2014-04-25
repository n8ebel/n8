//
//  GUI.cpp
//  DevApp
//
//  Created by Nate Ebel on 4/21/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#include "GUI.h"

gui::GUI::GUI() : m_hasFocus(false){
    
}

gui::GUI::~GUI(){
    
}

void gui::GUI::AddElement(gui::GUIElement* p_newWidget){
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