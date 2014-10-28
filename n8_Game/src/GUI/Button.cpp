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


/** Constructor
 *  Initializes parent class of GUIElement.
 *  Sets the button text
 *  Stores a command object to be run when the button is clicked down.
 *
 *  @param p_id The identifier of the button
 *  @param p_text The button text
 *  @param p_x The x position of the button
 *  @param p_y The y position of the button
 *  @param p_w The width of the button
 *  @param p_h The height of the button
 */
gui::Button::Button( std::string p_id,std::string p_text, int p_x, int p_y, int p_w, int p_h ) : GUIElement(p_id,p_x,p_y,p_w,p_h)
{
    m_text = p_text;
}

/** Constructor
 *  Initializes parent class of GUIElement.
 *  Sets the button text
 *  Stores a lambda function to be run when the button is clicked down.
 *
 *  @param p_id The identifier of the button
 *  @param p_text The button text
 *  @param p_x The x position of the button
 *  @param p_y The y position of the button
 *  @param p_w The width of the button
 *  @param p_h The height of the button
 *  @param p_func The lambda function to execute when button is clicked down
 */
gui::Button::Button(std::string p_id,std::string p_text, int p_x, int p_y, int p_w, int p_h, std::function<void()> p_func) : Button(p_id,p_text,p_x,p_y,p_w,p_h)
{
    m_function = p_func;
}

/** Destructor
 *  Destroys texture
 *  Sets command and lambda to nullptr
 */
gui::Button::~Button(){
    if (m_texture) {
        SDL_DestroyTexture(m_texture);
        m_texture = nullptr;
    }
    m_function = nullptr;
}

/** Builds the button.
 * Loads the rendered text texture using the game window pointer from 
 *  style pointer.
 */
void gui::Button::Build(n8::Window* window){
    TTF_Font* font = TTF_OpenFont(m_style.GetFontPath().c_str(), m_h-8);
    if (!font) {
        n8::Log::Error(TAG, "Button failed to load font: " + m_style.GetFontPath());
        return;
    }
    
    m_built = m_textTexture.loadFromRenderedText(  window->GetRenderer(), font, m_text.c_str(), m_style.GetColor(Style::EStyleColor::Font).GetColor() );
    
    TTF_CloseFont(font);
    
    if (!m_built) {
        n8::Log::Error(TAG, "Button failed to build");
    }
    
    GUIElement::Build(window);
    
}

/** Draws the button based on its current state
 *
 *  @param p_window Pointer to the game window object
 */
void gui::Button::Draw(n8::Window* p_window){
    
    SDL_Renderer* renderer= p_window->GetRenderer();
    
    if (m_state == State::Hovered) {
        drawHovered(renderer);
    }
    else if (m_state == State::Focused){
        drawFocused(renderer);
    }
    else if(m_state == State::Pressed){
        drawPressed(renderer);
    }
    else if(m_state == State::PressedAndHovered){
        drawPressedAndHovered(renderer);
    }
    else if (m_state == State::Selected){
        drawSelected(renderer);
    }
    else if (m_state == State::SelectedAndHovered){
        drawSelectedAndHovered(renderer);
    }
    else {
        drawNeutral(renderer);
    }
    
    if(m_textTexture.HasTexture()){
        int x = m_x + (m_w - m_textTexture.getWidth())/2;
        int y = m_y + (m_h - m_textTexture.getHeight())/2;
        m_textTexture.render(renderer, x,y);
    }
}

/** Updates the button every frame.
 *  Handles state transitions, and ensures that click events appear to user
 *   even if the click was too short to see.
 *
 *  @param p_currentTime Current game time
 */
bool gui::Button::Update(Uint32 p_currentTime){
    if(!m_mouseClickedDown){
        if (m_state == State::Pressed) {
            m_state = State::Selected;
        }
    }
    bool hasFocus = false;
    if(m_state == State::Pressed || m_state == State::Selected){
        hasFocus = true;
    }
    else{
        hasFocus = false;
    }
    
    return hasFocus;
}

void gui::Button::drawHovered(SDL_Renderer* p_renderer){
    n8::Color drawColor = m_style.GetColor(Style::EStyleColor::Button);
    n8::Color filterColor = m_style.GetColor(Style::EStyleColor::Hover);
    
    SDL_SetRenderDrawColor( p_renderer,
                           drawColor.GetR(),
                           drawColor.GetG(),
                           drawColor.GetB(),
                           drawColor.GetA()
                           );
    
    SDL_RenderFillRect( p_renderer, m_rectangle.GetRect() );
    
    SDL_SetRenderDrawBlendMode(p_renderer, SDL_BLENDMODE_BLEND);
    
    SDL_SetRenderDrawColor( p_renderer,
                           filterColor.GetR(),
                           filterColor.GetG(),
                           filterColor.GetB(),
                           filterColor.GetA()
                           );
    
    SDL_RenderFillRect( p_renderer, m_rectangle.GetRect() );
    
    SDL_SetRenderDrawBlendMode(p_renderer, SDL_BLENDMODE_NONE);
    
    SDL_RenderDrawRect(p_renderer, m_rectangle.GetRect());
    
}

void gui::Button::drawNeutral(SDL_Renderer* p_renderer){
    n8::Color drawColor = m_style.GetColor(Style::EStyleColor::Button);
    
    SDL_SetRenderDrawColor( p_renderer,
                           drawColor.GetR(),
                           drawColor.GetG(),
                           drawColor.GetB(),
                           drawColor.GetA()
                           );
    
    SDL_RenderFillRect( p_renderer, m_rectangle.GetRect() );
}
void gui::Button::drawFocused(SDL_Renderer* p_renderer){
    n8::Color drawColor = m_style.GetColor(Style::EStyleColor::Focus);
    
    SDL_SetRenderDrawColor( p_renderer,
                           drawColor.GetR(),
                           drawColor.GetG(),
                           drawColor.GetB(),
                           drawColor.GetA()
                           );
    
    SDL_RenderFillRect( p_renderer, m_rectangle.GetRect() );
}
void gui::Button::drawPressed(SDL_Renderer* p_renderer){
    n8::Color drawColor = m_style.GetColor(Style::EStyleColor::Pressed);
    
    SDL_SetRenderDrawColor( p_renderer,
                           drawColor.GetR(),
                           drawColor.GetG(),
                           drawColor.GetB(),
                           drawColor.GetA()
                           );
    
    SDL_RenderFillRect( p_renderer, m_rectangle.GetRect() );
}

void gui::Button::drawPressedAndHovered(SDL_Renderer* p_renderer){
    n8::Color drawColor = m_style.GetColor(Style::EStyleColor::Pressed);
    n8::Color filterColor = m_style.GetColor(Style::EStyleColor::Hover);
    
    SDL_SetRenderDrawColor( p_renderer,
                           drawColor.GetR(),
                           drawColor.GetG(),
                           drawColor.GetB(),
                           drawColor.GetA()
                           );
    
    SDL_RenderFillRect( p_renderer, m_rectangle.GetRect() );
    
    SDL_SetRenderDrawBlendMode(p_renderer, SDL_BLENDMODE_BLEND);
    
    SDL_SetRenderDrawColor( p_renderer,
                           filterColor.GetR(),
                           filterColor.GetG(),
                           filterColor.GetB(),
                           filterColor.GetA()
                           );
    
    SDL_RenderFillRect( p_renderer, m_rectangle.GetRect() );
    
    SDL_SetRenderDrawBlendMode(p_renderer, SDL_BLENDMODE_NONE);
    
    SDL_RenderDrawRect(p_renderer, m_rectangle.GetRect());
}

void gui::Button::drawSelected(SDL_Renderer* p_renderer){
    n8::Color drawColor = m_style.GetColor(Style::EStyleColor::Selected);
    
    SDL_SetRenderDrawColor( p_renderer,
                           drawColor.GetR(),
                           drawColor.GetG(),
                           drawColor.GetB(),
                           drawColor.GetA()
                           );
    
    SDL_RenderFillRect( p_renderer, m_rectangle.GetRect() );
}

void gui::Button::drawSelectedAndHovered(SDL_Renderer* p_renderer){
    n8::Color drawColor = m_style.GetColor(Style::EStyleColor::Selected);
    n8::Color filterColor = m_style.GetColor(Style::EStyleColor::Hover);
    
    SDL_SetRenderDrawColor( p_renderer,
                           drawColor.GetR(),
                           drawColor.GetG(),
                           drawColor.GetB(),
                           drawColor.GetA()
                           );
    
    SDL_RenderFillRect( p_renderer, m_rectangle.GetRect() );
    
    SDL_SetRenderDrawBlendMode(p_renderer, SDL_BLENDMODE_BLEND);
    
    SDL_SetRenderDrawColor( p_renderer,
                           filterColor.GetR(),
                           filterColor.GetG(),
                           filterColor.GetB(),
                           filterColor.GetA()
                           );
    
    SDL_RenderFillRect( p_renderer, m_rectangle.GetRect() );
    
    SDL_SetRenderDrawBlendMode(p_renderer, SDL_BLENDMODE_NONE);
    
    SDL_RenderDrawRect(p_renderer, m_rectangle.GetRect());

}
