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
    
    font = TTF_OpenFont( "stocky/stocky.ttf", 24 );
}

gui::InputBox::~InputBox(){
    
}

bool gui::InputBox::CheckMouseMove(){
    return false;
}

bool gui::InputBox::CheckMouseClickDown(int p_x, int p_y){
    if( p_x >= m_x && p_x <=m_x+m_w && p_y>=m_y && p_y<=m_y+m_h){
        SDL_StartTextInput();
        m_addingText = true;
        return true;
    }
    else{
        m_addingText = false;
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
            texture.loadFromRenderedText( p_window->GetRenderer(), font, m_inputString.c_str(), m_textColor );
        }
        //Text is empty
        else
        {
            //Render space texture
            texture.loadFromRenderedText(p_window->GetRenderer(), font, " ", m_textColor );
        }
    }
    
    SDL_Renderer* renderer= p_window->GetRenderer();
    
        SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
        SDL_RenderFillRect( renderer, &m_shape );
    
    texture.render(p_window->GetRenderer(), m_x+5,m_y+5);
}

void gui::InputBox::HandleKeyboardInput(SDL_Event* p_event){
    if(m_addingText){
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