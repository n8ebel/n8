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

#define TAG "Button"

gui::Button::Button( std::string p_id, int p_x, int p_y, int p_w, int p_h, n8::Command* p_command) : GUIElement(p_x,p_y,p_w,p_h)
{
    m_id = p_id;
    m_hover = false;
    m_pressed = false;
    m_command = p_command;
}

gui::Button::~Button(){
    
}

bool gui::Button::CheckMouseMove(){
    int x,y;
    SDL_GetMouseState(&x, &y);
    
    if( x >= m_x && x <=m_x+m_w && y>=m_y && y<=m_y+m_h){
        m_hover = true;
        return true;
    }
    else{
        m_hover = false;
        return false;
    }
}

bool gui::Button::CheckMouseClickDown(int p_x, int p_y){
    
    if( p_x >= m_x && p_x <=m_x+m_w && p_y>=m_y && p_y<=m_y+m_h){
        n8::Log::Debug(TAG, "Button " + m_id + " was clicked");
        m_pressed = true;
        if (m_command) {
            m_command->execute();
        }
        return true;
    }
    else{
        return false;
    }
    
    return false;
}

bool gui::Button::CheckMouseClickUp(int p_x, int p_y){
    
    m_pressed = false;
    
    return false;
}

void gui::Button::Draw(n8::Window* p_window){
    SDL_Renderer* renderer= p_window->GetRenderer();
    if(m_pressed){
        SDL_SetRenderDrawColor( renderer, 200, 200, 150, 255 );
        SDL_RenderFillRect( renderer, &m_shape );
    }
    else if (m_hover) {
        SDL_SetRenderDrawColor( renderer, 0, 255, 0, 255 );
        SDL_RenderFillRect( renderer, &m_shape );
    }
    else{
        SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );
        SDL_RenderFillRect( renderer, &m_shape );
    }
}