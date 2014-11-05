/*
 * GUIElement.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            4/20/14
 * Organization:    n8Tech
 *
 */

#include "GUIElement.h"


gui::GUIElement::GUIElement(n8::Window* p_window, std::string p_id, int p_x, int p_y, int p_w, int p_h) :
                                                                    m_rectangle(p_x,p_y,p_w,p_h),
                                                                    m_texture(nullptr),
                                                                    m_style("Roboto.ttf")
{
    m_id = p_id;
    m_x = m_rectangle.GetX();
    m_y = m_rectangle.GetY();
    m_w = m_rectangle.GetW();
    m_h = m_rectangle.GetH();
    m_state = State::Neutral;
    m_mouseClickedDown = false;
    m_timeClickedDown = 0;
    m_function = nullptr;
}

gui::GUIElement::~GUIElement(){
    if (m_texture) {
        SDL_DestroyTexture(m_texture);
        m_texture = nullptr;
    }
}

/** Moves an element to the new specified position.
 *
 *  @param p_x The new x position of the element
 *  @param p_y The new y position of the element
 */
void gui::GUIElement::SetPosition(int p_x, int p_y){
    m_rectangle.Reposition(p_x, p_y);
}

/** Moves an element by the specified amount.
 *
 *  @param p_xOffset The amount to move the element in the x direction.
 *  @param p_yOffset The amount to move the element in the y direction.
 */
void gui::GUIElement::OffsetPosition(int p_xOffset, int p_yOffset){
    cout << "offsetting position" << endl;
    cout << "starting x = " << m_x << endl;
    m_rectangle.Offset(p_xOffset, p_yOffset);
    m_x = m_rectangle.GetX();
    m_y = m_rectangle.GetY();
    cout << "ending x = " << m_x << endl;
}

void gui::GUIElement::SetSize(int width, int height){
    m_rectangle.Resize(width, height);
}

void gui::GUIElement::SetWidth(int width){
    m_rectangle.Resize(width, m_rectangle.GetH());
}

void gui::GUIElement::SetHeight(int height){
    m_rectangle.Resize(m_rectangle.GetW(), height);
}

/** Sets the style pointer of the element.
 *
 *  @param p_style A pointer to the new sytle object for the element.
 */
void gui::GUIElement::SetStyle(Style p_style){
    m_style = p_style;
}

void gui::GUIElement::SetColor(Style::EStyleColor p_color, int p_r, int p_g, int p_b){
    SetColor(p_color, p_r, p_g, p_b, Style::DEFAULT_ALPHA);
}

void gui::GUIElement::SetColor(Style::EStyleColor p_color, int p_r, int p_g, int p_b, int p_a){
    m_style.SetColor(p_color, p_r, p_g, p_b, p_a);
}

void gui::GUIElement::SetState(gui::GUIElement::State newState){
    m_state = newState;
}

gui::GUIElement::State gui::GUIElement::GetState(){
    return m_state;
}

/** Handles mouse move event
 *
 *  @param p_x The x position of the mouse move
 *  @param p_y The y position of the mouse move
 *
 *  @return True if mouse if moving within the button
 */
bool gui::GUIElement::CheckMouseMove(int p_x, int p_y){
    if (positionWithinElement(p_x, p_y)) {
        if (m_state == State::Pressed) {
            m_state = State::PressedAndHovered;
        }
        else if(m_state == State::Selected){
            m_state = State::SelectedAndHovered;
        }
        else if(m_state == State::Neutral || m_state == State::Focused){
            m_state = State::Hovered;
        }
        return true;
    }else{
        if (m_state == State::PressedAndHovered) {
            m_state = State::Pressed;
        }
        else if(m_state == State::SelectedAndHovered){
            m_state = State::Selected;
        }
        else if(m_state == State::Hovered || m_state == State::Focused){
            m_state = State::Neutral;
        }
        return false;
    }
}

/** Checks whether the element was clicked down
 *
 *
 *  @param p_x The x coordinate of the mouse click
 *  @param p_y The y coordinate of the mouse click
 *
 *  @return bool Returns true if element was clicked up
 */
bool gui::GUIElement::CheckMouseClickDown(int p_x, int p_y){
    
    if( positionWithinElement(p_x, p_y)){
        m_state = State::PressedAndHovered;
        m_mouseClickedDown = true;
        m_timeClickedDown = SDL_GetTicks();
        
        return true;
    }
    else{
        return false;
    }
    
    return false;
}

/** Checks whether the element was clicked
 *
 *
 *  @param p_x The x coordinate of the mouse click
 *  @param p_y The y coordinate of the mouse click
 *
 *  @return bool Returns true if element was clicked up
 */
bool gui::GUIElement::CheckMouseClickUp(int p_x, int p_y){
    
    if (!m_mouseClickedDown) {
        return false;
    }
    
    m_mouseClickedDown = false;
    bool mouseUpInElement = positionWithinElement(p_x, p_y);
    
    if(mouseUpInElement){
        m_state = State::SelectedAndHovered;
        if (m_function != nullptr) {
            m_function();
        }
        return true;
    }else if(!mouseUpInElement){
        m_state = State::Neutral;
        return false;
    }
    
    return false;
}

/**
 *  Sets a function to be called on click
 */
void gui::GUIElement::setClickHandler(std::function<void()> function){
    m_function = function;
}

/**
 *  Checks whether a specified location is within the bounds of the element.
 */
bool gui::GUIElement::positionWithinElement(int p_x, int p_y){
    if( p_x >= m_x && p_x < m_x + m_w && p_y >= m_y && p_y < m_y + m_h){
        return true;
    }else{
        return false;
    }
}