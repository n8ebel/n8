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

/** Constructor
 *
 *  @param p_x The x position of the container
 *  @param p_y The y position of the container
 *  @param p_w The width of the container
 *  @param p_h The height of the container
 */
gui::Container::Container(int p_x, int p_y, int p_w, int p_h) : GUIElement(p_x,p_y,p_w,p_h)
{
    m_hasFocus = false;
}

/** Destructor
 *  Destroys texture memory for current background, and deletes all elements stored in the elements list.
 */
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

void gui::Container::Build(){
    for (auto widget : m_guiElements){
        widget->Build();
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

void gui::Container::OffsetPosition(int p_xOffset, int p_yOffset){
    m_rectangle.Offset(p_xOffset, p_yOffset);
    
    for (auto element : m_guiElements) {
        element->OffsetPosition(p_xOffset, p_yOffset);
    }
}