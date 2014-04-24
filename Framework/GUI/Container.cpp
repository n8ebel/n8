//
//  Container.cpp
//  DevApp
//
//  Created by Nate Ebel on 4/21/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#include "Container.h"

gui::Container::Container(int p_x, int p_y, int p_w, int p_h){
    m_x = m_shape.x = p_x;
    m_y = m_shape.y = p_y;
    m_w = m_shape.w = p_w;
    m_h = m_shape.h = p_h;
}

gui::Container::~Container(){
    
}

bool gui::Container::CheckMouseClickDown(int p_x, int p_y){
    for (const auto& widget : m_elements){
        if ( widget->CheckMouseClickDown(p_x, p_y) ){
            return true;
        }
    }
    
    return false;
}

bool gui::Container::CheckMouseClickUp(int p_x, int p_y){
    for (const auto& widget : m_elements){
        if ( widget->CheckMouseClickUp(p_x, p_y) ){
            return true;
        }
    }
    
    return false;
}

bool gui::Container::CheckMouseMove(){
    for (const auto& widget : m_elements){
        if ( widget->CheckMouseMove() ){
            return true;
        }
    }
    
    return false;
}

void gui::Container::Draw(n8::Window* p_window){
    SDL_Renderer* renderer= p_window->GetRenderer();
    
    SDL_SetRenderDrawColor( renderer, 255, 0, 255, 255 );
    SDL_RenderFillRect( renderer, &m_shape );
    
    for (const auto& widget : m_elements){
        widget->Draw(p_window);
    }
    
}

void gui::Container::AddElement(GUIElement* p_widget){
    if (p_widget) {
        m_elements.push_back(p_widget);
    }
}