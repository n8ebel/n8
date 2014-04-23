//
//  GUI.cpp
//  DevApp
//
//  Created by Nate Ebel on 4/21/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#include "GUI.h"

gui::GUI::GUI(){
    
}

gui::GUI::~GUI(){
    
}

void gui::GUI::AddElement(gui::Widget* p_newWidget){
    m_guiElements.push_back(p_newWidget);
}

void gui::GUI::Process(){
    for (int i = 0; i < m_guiElements.size(); i++) {
        m_guiElements[i]->CheckMouse();
    }
}

void gui::GUI::Draw(n8::Window* p_window){
    for (int i = 0; i < m_guiElements.size(); i++) {
        m_guiElements[i]->Draw(p_window);
    }
}