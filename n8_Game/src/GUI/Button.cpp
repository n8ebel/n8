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
gui::Button::Button( std::string p_id,std::string p_text, int p_x, int p_y, int p_w, int p_h ) : GUIElement(p_x,p_y,p_w,p_h)
{
    m_id = p_id;
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
    
    
    m_built = m_textTexture.loadFromRenderedText(  window->GetRenderer(), m_style.GetFont()->GetFont(), m_text.c_str(), m_style.GetColor(Style::EStyleColor::Font).GetColor() );
    
    if (!m_built) {
        n8::Log::Error(TAG, "Label failed to build");
    }
    
    GUIElement::Build(window);
    
}

/** Draws the button based on its current state
 *
 *  @param p_window Pointer to the game window object
 */
void gui::Button::Draw(n8::Window* p_window){
    
    SDL_Renderer* renderer= p_window->GetRenderer();
    if(m_pressed){
        SDL_SetRenderDrawColor( renderer,
                               m_style.GetColor(Style::EStyleColor::Pressed).GetR(),
                               m_style.GetColor(Style::EStyleColor::Pressed).GetG(),
                               m_style.GetColor(Style::EStyleColor::Pressed).GetB(),
                               m_style.GetColor(Style::EStyleColor::Pressed).GetA()
                               );
        SDL_RenderFillRect( renderer, m_rectangle.GetRect() );
    }
    else if (m_hover) {
        SDL_SetRenderDrawColor( renderer,
                               m_style.GetColor(Style::EStyleColor::Hover).GetR(),
                               m_style.GetColor(Style::EStyleColor::Hover).GetG(),
                               m_style.GetColor(Style::EStyleColor::Hover).GetB(),
                               m_style.GetColor(Style::EStyleColor::Hover).GetA()
                               );
        SDL_RenderFillRect( renderer, m_rectangle.GetRect() );
    }
    else{
        SDL_SetRenderDrawColor( renderer,
                               m_style.GetColor(Style::EStyleColor::Button).GetR(),
                               m_style.GetColor(Style::EStyleColor::Button).GetG(),
                               m_style.GetColor(Style::EStyleColor::Button).GetB(),
                               m_style.GetColor(Style::EStyleColor::Button).GetA()
                               );
        SDL_RenderFillRect( renderer, m_rectangle.GetRect() );
    }
    
    if(m_textTexture.HasTexture()){
        int x = m_rectangle.GetX()+ (m_rectangle.GetW()-m_textTexture.getWidth())/2;
        int y = m_rectangle.GetY()+ (m_rectangle.GetH()-m_textTexture.getHeight())/2;
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
    if(SDL_GetTicks() - m_timeClickedDown > 100 && !m_mouseClickedDown){
        m_pressed = false;
    }
    if(m_pressed){
        m_hasFocus = true;
    }
    else{
        m_hasFocus = false;
    }
    return m_hasFocus;
}