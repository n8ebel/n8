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
gui::Button::Button(std::shared_ptr<n8::Window> p_window, std::string p_id,std::string p_text, int p_x, int p_y, int p_w, int p_h ) : GUIElement(p_window, p_id,p_x,p_y,p_w,p_h)
{
    m_text = p_text;
    
    loadFontTexture(Style::DEFAULT_FONT_SIZE);
    
    if (!m_built) {
        n8::Log::Error(TAG, "Button failed to build");
    }

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
gui::Button::Button(std::shared_ptr<n8::Window> p_window, std::string p_id,std::string p_text, int p_x, int p_y, int p_w, int p_h, std::function<void()> p_func) : Button(p_window, p_id,p_text,p_x,p_y,p_w,p_h)
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

void gui::Button::SetTextSize(int textSize){
    loadFontTexture(textSize);
}

/** Draws the button based on its current state
 *
 *  @param p_window Pointer to the game window object
 */
void gui::Button::Draw(const std::shared_ptr<n8::Window> p_window) const{
    
    if (m_state == State::Hovered) {
        drawHovered(p_window);
    }
    else if (m_state == State::Focused){
        drawFocused(p_window);
    }
    else if(m_state == State::Pressed){
        drawPressed(p_window);
    }
    else if(m_state == State::PressedAndHovered){
        drawPressedAndHovered(p_window);
    }
    else if (m_state == State::Selected){
        drawSelected(p_window);
    }
    else if (m_state == State::SelectedAndHovered){
        drawSelectedAndHovered(p_window);
    }
    else {
        drawNeutral(p_window);
    }
    
    if (m_textTexture) {
        int x = m_x + (m_w - m_textTexture->GetWidth())/2;
        int y = m_y + (m_h - m_textTexture->GetHeight())/2;
        m_textTexture->Render(const_cast<SDL_Renderer*>(&p_window->GetRenderer()), x,y);
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

void gui::Button::drawHovered(const std::shared_ptr<n8::Window> p_window) const{
    auto renderer = const_cast<SDL_Renderer*>(&p_window->GetRenderer());
    n8::Color drawColor = m_style.GetColor(Style::EStyleColor::Button);
    n8::Color filterColor = m_style.GetColor(Style::EStyleColor::Hover);
    
    SDL_SetRenderDrawColor( renderer,
                           drawColor.GetR(),
                           drawColor.GetG(),
                           drawColor.GetB(),
                           drawColor.GetA()
                           );
    
    SDL_RenderFillRect( renderer, &m_rectangle.GetRect() );
    
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    
    SDL_SetRenderDrawColor( renderer,
                           filterColor.GetR(),
                           filterColor.GetG(),
                           filterColor.GetB(),
                           filterColor.GetA()
                           );
    
    SDL_RenderFillRect( renderer, &m_rectangle.GetRect() );
    
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
    
    SDL_RenderDrawRect(renderer, &m_rectangle.GetRect());
    
}

void gui::Button::drawNeutral(const std::shared_ptr<n8::Window> p_window) const{
    auto renderer = const_cast<SDL_Renderer*>(&p_window->GetRenderer());
    n8::Color drawColor = m_style.GetColor(Style::EStyleColor::Button);
    n8::Color outlineColor = m_style.GetColor(Style::EStyleColor::ButtonOutline);
    
    SDL_SetRenderDrawColor( renderer,
                           drawColor.GetR(),
                           drawColor.GetG(),
                           drawColor.GetB(),
                           drawColor.GetA()
                           );
    
    SDL_RenderFillRect( renderer, &m_rectangle.GetRect() );
    
    SDL_SetRenderDrawColor( renderer,
                           outlineColor.GetR(),
                           outlineColor.GetG(),
                           outlineColor.GetB(),
                           outlineColor.GetA()
                           );
    
    SDL_RenderDrawRect(renderer, &m_rectangle.GetRect());
}
void gui::Button::drawFocused(const std::shared_ptr<n8::Window> p_window) const{
    auto renderer = const_cast<SDL_Renderer*>(&p_window->GetRenderer());
    n8::Color drawColor = m_style.GetColor(Style::EStyleColor::Focus);
    
    SDL_SetRenderDrawColor( renderer,
                           drawColor.GetR(),
                           drawColor.GetG(),
                           drawColor.GetB(),
                           drawColor.GetA()
                           );
    
    SDL_RenderFillRect( renderer, &m_rectangle.GetRect() );
}

void gui::Button::drawPressed(const std::shared_ptr<n8::Window> p_window) const{
    auto renderer = const_cast<SDL_Renderer*>(&p_window->GetRenderer());
    n8::Color drawColor = m_style.GetColor(Style::EStyleColor::Pressed);
    
    SDL_SetRenderDrawColor( renderer,
                           drawColor.GetR(),
                           drawColor.GetG(),
                           drawColor.GetB(),
                           drawColor.GetA()
                           );
    
    SDL_RenderFillRect( renderer, &m_rectangle.GetRect() );
}

void gui::Button::drawPressedAndHovered(const std::shared_ptr<n8::Window> p_window) const{
    auto renderer = const_cast<SDL_Renderer*>(&p_window->GetRenderer());
    n8::Color drawColor = m_style.GetColor(Style::EStyleColor::Pressed);
    n8::Color filterColor = m_style.GetColor(Style::EStyleColor::Hover);
    
    SDL_SetRenderDrawColor( renderer,
                           drawColor.GetR(),
                           drawColor.GetG(),
                           drawColor.GetB(),
                           drawColor.GetA()
                           );
    
    SDL_RenderFillRect( renderer, &m_rectangle.GetRect() );
    
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    
    SDL_SetRenderDrawColor( renderer,
                           filterColor.GetR(),
                           filterColor.GetG(),
                           filterColor.GetB(),
                           filterColor.GetA()
                           );
    
    SDL_RenderFillRect( renderer, &m_rectangle.GetRect() );
    
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
    
    SDL_RenderDrawRect(renderer, &m_rectangle.GetRect());
}

void gui::Button::drawSelected(const std::shared_ptr<n8::Window> p_window) const{
    auto renderer = const_cast<SDL_Renderer*>(&p_window->GetRenderer());
    n8::Color drawColor = m_style.GetColor(Style::EStyleColor::Selected);
    
    SDL_SetRenderDrawColor( renderer,
                           drawColor.GetR(),
                           drawColor.GetG(),
                           drawColor.GetB(),
                           drawColor.GetA()
                           );
    
    SDL_RenderFillRect( renderer, &m_rectangle.GetRect() );
}

void gui::Button::drawSelectedAndHovered(const std::shared_ptr<n8::Window> p_window) const{
    auto renderer = const_cast<SDL_Renderer*>(&p_window->GetRenderer());
    n8::Color drawColor = m_style.GetColor(Style::EStyleColor::Selected);
    n8::Color filterColor = m_style.GetColor(Style::EStyleColor::Hover);
    
    SDL_SetRenderDrawColor( renderer,
                           drawColor.GetR(),
                           drawColor.GetG(),
                           drawColor.GetB(),
                           drawColor.GetA()
                           );
    
    SDL_RenderFillRect( renderer, &m_rectangle.GetRect() );
    
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    
    SDL_SetRenderDrawColor( renderer,
                           filterColor.GetR(),
                           filterColor.GetG(),
                           filterColor.GetB(),
                           filterColor.GetA()
                           );
    
    SDL_RenderFillRect( renderer, &m_rectangle.GetRect() );
    
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
    
    SDL_RenderDrawRect(renderer, &m_rectangle.GetRect());

}

void gui::Button::loadFontTexture(int textSize){
    
    // If there is no text for the button, dont bother creating a text texture for it
    if (m_text.empty()) {
        m_built = true;
        return;
    }
    
    // Build
    TTF_Font* font = TTF_OpenFont(m_style.GetFontPath().c_str(), textSize);
    
    if (!font) {
        n8::Log::Error(TAG, "Button failed to load font: " + m_style.GetFontPath());
    }else{
        m_textTexture = std::make_unique<n8::Texture>("", const_cast<SDL_Renderer*>(&m_window->GetRenderer()), font, m_text.c_str(),
                                                      m_style.GetColor(Style::EStyleColor::Font).GetColor() );
    }
    
    m_built = m_textTexture != nullptr;
    
    TTF_CloseFont(font);
}
