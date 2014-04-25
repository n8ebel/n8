//
//  InputBox.cpp
//  DevApp
//
//  Created by Nate Ebel on 4/24/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#include "InputBox.h"

gui::InputBox::InputBox(int p_x, int p_y, int p_w, int p_h) : GUIElement(p_x,p_y,p_w,p_h){
    m_textColor = { 0, 0, 0, 0xFF };
    m_inputString = "";
    m_cursorShown = false;
    m_lastTime = 0;
    m_hasFocus = false;
    m_font = TTF_OpenFont( "stocky/stocky.ttf", p_h - 20 );
}

gui::InputBox::~InputBox(){
    if (m_texture) {
        SDL_DestroyTexture(m_texture);
        m_texture = nullptr;
    }
    if (m_font){
        TTF_CloseFont(m_font);
    }
}

bool gui::InputBox::CheckMouseMove(){
    return false;
}

bool gui::InputBox::CheckMouseClickDown(int p_x, int p_y){
    if( p_x >= m_x && p_x <=m_x+m_w && p_y>=m_y && p_y<=m_y+m_h){
        SDL_StartTextInput();
        m_hasFocus = true;
        return true;
    }
    else{
        m_hasFocus = false;
        SDL_StopTextInput();
        return false;
    }
    
    return false;
}

bool gui::InputBox::CheckMouseClickUp(int p_x, int p_y){
    
    return false;
}

void gui::InputBox::Draw(n8::Window* p_window){
    
    //Rerender text if needed
    if( m_updateTexture )
    {
        //Text is not empty
        if( m_inputString != "" )
        {
            //Render new text
            texture.loadFromRenderedText( p_window->GetRenderer(), m_font, m_inputString.c_str(), m_textColor );
        }
        //Text is empty
        else
        {
            //Render space texture
            texture.loadFromRenderedText(p_window->GetRenderer(), m_font, " ", m_textColor );
        }
    }
    
    SDL_Renderer* renderer= p_window->GetRenderer();
    
    SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
    SDL_RenderFillRect( renderer, &m_shape );
    
    if (m_hasFocus) {
        SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );
        SDL_RenderDrawRect(renderer, &m_shape);
    }
    
    texture.render(p_window->GetRenderer(), m_x+5,m_y+5);
    
    if (m_cursorShown && m_hasFocus) {
        int x = m_x+2+texture.getWidth()+5;
        int y1 = m_y+10;
        int y2 = m_y + m_h - 10;
        SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
        SDL_RenderDrawLine(renderer, x, y1, x, y2);
    }
}

void gui::InputBox::HandleKeyboardInput(SDL_Event* p_event){
    if(m_hasFocus){
        SDL_Event e = *p_event;
        if( e.type == SDL_KEYDOWN )
        {
            //Handle backspace
            if( e.key.keysym.sym == SDLK_BACKSPACE && m_inputString.length() > 0 )
            {
                //lop off character
                m_inputString.pop_back();
                m_updateTexture = true;
            }
            //Handle copy
            else if( e.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL )
            {
                m_inputString = SDL_SetClipboardText( m_inputString.c_str() );
            }
            //Handle paste
            else if( e.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL )
            {
                m_inputString = SDL_GetClipboardText();
                m_updateTexture = true;
            }
        }
        //Special text input event
        else if( e.type == SDL_TEXTINPUT )
        {
            //Not copy or pasting
            if( !( ( e.text.text[ 0 ] == 'c' || e.text.text[ 0 ] == 'C' ) && ( e.text.text[ 0 ] == 'v' || e.text.text[ 0 ] == 'V' ) && SDL_GetModState() & KMOD_CTRL ) )
            {
                //Append character
                m_inputString += e.text.text;
                m_updateTexture = true;
            }
        }
    }
    
}

bool gui::InputBox::Update(Uint32 p_currentTime){
    if ( (p_currentTime - m_lastTime) > 500) {
        m_cursorShown = !m_cursorShown;
        m_lastTime = p_currentTime;
    }
    
    return m_hasFocus;
}