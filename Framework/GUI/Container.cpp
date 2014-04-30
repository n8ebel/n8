/*
 * Container.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            4/20/14
 * Organization:    n8Tech
 *
 */

#include "Container.h"

gui::Container::Container(int p_x, int p_y, int p_w, int p_h) : GUIElement(p_x,p_y,p_w,p_h)
{
    m_hasFocus = false;
}

gui::Container::~Container(){
    if (m_texture) {
        SDL_DestroyTexture(m_texture);
        m_texture = nullptr;
    }
    
    for (auto element : m_guiElements){
        if (element) {
            delete element;
            element = nullptr;
        }
    }
}

bool gui::Container::CheckMouseClickDown(int p_x, int p_y){
    for (const auto& widget : m_guiElements){
        if ( widget->CheckMouseClickDown(p_x, p_y) ){
            return true;
        }
    }
    
    return false;
}

bool gui::Container::CheckMouseClickUp(int p_x, int p_y){
    for (const auto& widget : m_guiElements){
        if ( widget->CheckMouseClickUp(p_x, p_y) ){
            return true;
        }
    }
    
    return false;
}

bool gui::Container::CheckMouseMove(){/*
    for (const auto& widget : m_guiElements){
        if ( widget->CheckMouseMove() ){
            return true;
        }
    }
    */
    for_each(m_guiElements.begin(), m_guiElements.end(), [](GUIElement* x){
        x->CheckMouseMove();
    } );
        
    
    
    return false;
}

void gui::Container::SetStyle(Style* p_style){
    m_style = p_style;
    for (auto element : m_guiElements){
        element->SetStyle(p_style);
    }
}

void gui::Container::Draw(n8::Window* p_window){
    SDL_Renderer* renderer= p_window->GetRenderer();
    
    SDL_SetRenderDrawColor( renderer, m_style->GetColor(Style::EStyleColor::Container).GetR(), m_style->GetColor(Style::EStyleColor::Container).GetG(), m_style->GetColor(Style::EStyleColor::Container).GetB(), m_style->GetColor(Style::EStyleColor::Container).GetA() );
    SDL_RenderFillRect( renderer, m_rectangle.GetRect() );
    
    for (const auto& widget : m_guiElements){
        widget->Draw(p_window);
    }
    
}

void gui::Container::AddElement(GUIElement* p_widget){
    if (p_widget) {
        m_guiElements.push_back(p_widget);
    }
}

bool gui::Container::Update(Uint32 p_currentTime){
    m_hasFocus = false;
    for(auto element : m_guiElements){
        if(element->Update(p_currentTime)){
            m_hasFocus = true;
        }
    }
    
    return m_hasFocus;
}

void gui::Container::OffsetPosition(int p_x, int p_y){
    m_x += p_x;
    m_y += p_y;
    
    for (auto element : m_guiElements) {
        element->OffsetPosition(p_x, p_y);
    }
}