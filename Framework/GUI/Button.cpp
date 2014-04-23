/*
 * Button.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            4/20/14
 * Organization:    n8Tech
 *
 */
#include <iostream>
#include "Button.h"

gui::Button::Button( int p_x, int p_y, int p_w, int p_h)
{
    m_x = m_buttonShape.x = p_x;
    m_y = m_buttonShape.y = p_y;
    m_w = m_buttonShape.w = p_w;
    m_h = m_buttonShape.h = p_h;
    m_hover = false;
}

gui::Button::~Button(){
    
}

bool gui::Button::CheckMouse(){
    int x,y;
    SDL_GetMouseState(&x, &y);
    
    if( x >= m_x && x <=m_x+m_w && y>=m_y && y<=m_y+m_h){
        m_hover = true;
    }
    else{
        m_hover = false;
    }
    
    return false;
}

void gui::Button::Draw(n8::Window* p_window){
    SDL_Renderer* renderer= p_window->GetRenderer();
    if (m_hover) {
        SDL_SetRenderDrawColor( renderer, 0, 255, 0, 255 );
        SDL_RenderFillRect( renderer, &m_buttonShape );
    }
    else{
        SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );
        SDL_RenderFillRect( renderer, &m_buttonShape );
    }
}