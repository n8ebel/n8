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
gui::Container::Container(n8::Window* p_window, std::string p_id, int p_x, int p_y, int p_w, int p_h) : GUIElement(p_window, p_id,p_x,p_y,p_w,p_h)
{
    
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

/** Checks all added elements for whether or not the mouse 
 *  click took place within that element.
 *
 *  @param p_x The x coordinate of the mouse click
 *  @param p_y The y coordinate of the mouse click
 *
 *  @return bool Returns true if any element was clicked
 */
bool gui::Container::CheckMouseClickDown(int p_x, int p_y){
    for (const auto element : m_guiElements){
        if ( element->CheckMouseClickDown(p_x, p_y) ){
            return true;
        }
    }
    
    return false;
}

/** Checks all added elements for whether or not the mouse
 *  click took place within that element.
 *
 *  @param p_x The x coordinate of the mouse click
 *  @param p_y The y coordinate of the mouse click
 *
 *  @return bool Returns true if any element was clicked up
 */
bool gui::Container::CheckMouseClickUp(int p_x, int p_y){
    for (const auto& widget : m_guiElements){
        if ( widget->CheckMouseClickUp(p_x, p_y) ){
            return true;
        }
    }
    
    return false;
}

/** Handles mouse move event for all added elements
 *
 *  @param p_x The x position of the mouse move
 *  @param p_y The y position of the mouse move
 *
 *  @return True if any element handled the event
 */
bool gui::Container::CheckMouseMove(int p_x, int p_y){
    for (const auto& widget : m_guiElements){
        if ( widget->CheckMouseMove(p_x,p_y) ){
            return true;
        }
    }
    
    return false;
}

/** Sets the style pointer of the container and all elements added to the container
 *
 *  @param p_style Pointer to a style object
 */
void gui::Container::SetStyle(Style p_style){
    m_style = p_style;
    for (auto element : m_guiElements){
        element->SetStyle(p_style);
    }
}

/** Draws the container to the given window
 *
 *  @param p_window The game's window that can be drawn to
 */
void gui::Container::Draw(const std::shared_ptr<n8::Window> p_window){
    SDL_Renderer* renderer = const_cast<SDL_Renderer*>(&p_window->GetRenderer());
    
    SDL_SetRenderDrawColor( renderer, m_style.GetColor(Style::EStyleColor::Container).GetR(), m_style.GetColor(Style::EStyleColor::Container).GetG(), m_style.GetColor(Style::EStyleColor::Container).GetB(), m_style.GetColor(Style::EStyleColor::Container).GetA() );
    SDL_RenderFillRect( renderer, &m_rectangle.GetRect() );
    
    for (const auto& widget : m_guiElements){
        widget->Draw(p_window);
    }
    
}

/** Adds an element to the elements list
 *
 *  @param p_widget The gui element to add
 */
void gui::Container::AddElement(GUIElement* pElement){
    if (pElement) {
        pElement->OffsetPosition(m_x, m_y);
        m_guiElements.push_back(pElement);
    }
}

/**  Updates the container and all added elements.
 *  Sets the focus of the container to false, and then sets it to true 
 *  if any added element has the focus.
 *
 *  @return True if the container, or any of its added elements has the focus
 */
bool gui::Container::Update(Uint32 p_currentTime){
    bool hasFocus = false;
    for(auto element : m_guiElements){
        if(element->Update(p_currentTime)){
            hasFocus = true;
        }
    }
    
    return hasFocus;
}

/**  Offsets the position of the container and all of its added
 *  elements by a specified amount.
 *
 *  @param p_xOffset The horizontal amount to offset the elements
 *  @param p_yOffset The vertical amount to offset the elements
 */
void gui::Container::OffsetPosition(int p_xOffset, int p_yOffset){
    m_rectangle.Offset(p_xOffset, p_yOffset);
    
    for (auto element : m_guiElements) {
        element->OffsetPosition(p_xOffset, p_yOffset);
    }
}