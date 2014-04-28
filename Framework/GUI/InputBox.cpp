/*
 * InputBox.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            4/24/14
 * Organization:    n8Tech
 *
 */

#include "InputBox.h"

gui::InputBox::InputBox(int p_x, int p_y, int p_w, int p_h) : GUIElement(p_x,p_y,p_w,p_h){
    m_textColor = { 0, 0, 0, 0xFF };
    m_inputString = "";
    m_cursorShown = false;
    m_lastTime = 0;
    m_hasFocus = false;
    m_updateTexture = true;
    m_font = TTF_OpenFont( "stocky/stocky.ttf", p_h - M_TEXT_OFFSET_Y*2 );
    if (m_font == nullptr) {
        std::cout << SDL_GetError() << std::endl;
    }
}

gui::InputBox::InputBox(int p_x, int p_y, int p_w, int p_h, std::string p_hint) : GUIElement(p_x,p_y,p_w,p_h){
    
    m_textColor = { 0, 0, 0, 0xFF };
    m_hintString = p_hint;
    m_inputString = "";
    m_cursorShown = false;
    m_lastTime = 0;
    m_hasFocus = false;
    m_updateTexture = true;
    m_font = TTF_OpenFont( "stocky/stocky.ttf", p_h - M_TEXT_OFFSET_Y*2 );
    if (m_font == nullptr) {
        std::cout << SDL_GetError() << std::endl;
    }
}

gui::InputBox::~InputBox(){
    if (m_texture != nullptr) {
        SDL_DestroyTexture(m_texture);
        m_texture = nullptr;
    }
    if (m_font != nullptr){
        
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
    m_updateTexture = true;
    return false;
}

bool gui::InputBox::CheckMouseClickUp(int p_x, int p_y){
    
    return false;
}

void gui::InputBox::Draw(n8::Window* p_window){
    
    if(m_updateTexture){
        UpdateTexture(p_window);
    }
    
    SDL_Renderer* renderer= p_window->GetRenderer();
    
    //draw box background
    SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
    SDL_RenderFillRect( renderer, m_rectangle.GetRect() );
    
    //draw outline if has focus
    if (m_hasFocus) {
        SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );
        SDL_RenderDrawRect(renderer, m_rectangle.GetRect());
    }
    
    //draw text
    if (m_hintString != "" || m_inputString != "") {
        m_textTexture.render(p_window->GetRenderer(),   m_x + M_TEXT_OFFSET_X,
                             m_y + M_TEXT_OFFSET_Y);
    }
    
    //draw cursor
    if (m_cursorShown && m_hasFocus) {
        int x = m_x + M_CURSOR_OFFSET_X + m_textTexture.getWidth() + M_TEXT_OFFSET_X;
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

std::string gui::InputBox::GetText(){
    return m_inputString;
}

void gui::InputBox::UpdateTexture(n8::Window* p_window){
    //Text is not empty
    if( m_inputString.length() > 0)
    {
        //load input text to texture
        m_textTexture.loadFromRenderedText( p_window->GetRenderer(), m_font, m_inputString.c_str(), m_textColor );
    }
    //Text is empty
    else
    {
        if (m_hintString != "" && !m_hasFocus) {
            //load hint text to texture
            m_textTexture.loadFromRenderedText(p_window->GetRenderer(), m_font, m_hintString, m_textColor );
        }
        else{
            //load empty texture
            m_textTexture.loadFromRenderedText(p_window->GetRenderer(), m_font, " ", m_textColor );
        }
    }
}