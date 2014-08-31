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
 *  @param p_command The command to execute when button is clicked down
 */
gui::Button::Button( std::string p_id,std::string p_text, int p_x, int p_y, int p_w, int p_h, n8::Command* p_command) : GUIElement(p_x,p_y,p_w,p_h)
{
    m_id = p_id;
    m_text = p_text;
    m_hover = false;
    m_pressed = false;
    m_mouseClickedDown = false;
    m_timeClickedDown = 0;
    m_hasFocus = false;
    m_command = p_command;
    m_function = nullptr;
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
gui::Button::Button(std::string p_id,std::string p_text, int p_x, int p_y, int p_w, int p_h, std::function<void()> p_func) : GUIElement(p_x,p_y,p_w,p_h)
{
    m_id = p_id;
    m_text = p_text;
    m_hover = false;
    m_pressed = false;
    m_mouseClickedDown = false;
    m_timeClickedDown = 0;
    m_hasFocus = false;
    m_command = nullptr;
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
    m_command = nullptr;
    m_function = nullptr;
}

/** Builds the button.
 * Loads the rendered text texture using the game window pointer from 
 *  style pointer.
 */
void gui::Button::Build(){
    
    if (m_style) {
        m_built = m_textTexture.loadFromRenderedText(  m_style->GetWindow()->GetRenderer(), m_style->GetFont()->GetFont(), m_text.c_str(), m_style->GetColor(Style::EStyleColor::Font).GetColor() );
    }
    
    if (!m_built) {
        n8::Log::Error(TAG, "Label failed to build");
    }
    
}

/** Handles mouse move event
 *
 *  @param p_x The x position of the mouse move
 *  @param p_y The y position of the mouse move
 *
 *  @return True if mouse if moving within the button
 */
bool gui::Button::CheckMouseMove(int p_x, int p_y){
    
    if( p_x >= m_rectangle.GetX() && p_x <= m_rectangle.GetX() + m_rectangle.GetW() && p_y >= m_rectangle.GetY() && p_y <= m_rectangle.GetY() + m_rectangle.GetH()){
        m_hover = true;
        return true;
    }
    else{
        m_hover = false;
        return false;
    }
}

/** Checks whether the button was clicked down
 *
 *
 *  @param p_x The x coordinate of the mouse click
 *  @param p_y The y coordinate of the mouse click
 *
 *  @return bool Returns true if button was clicked up
 */
bool gui::Button::CheckMouseClickDown(int p_x, int p_y){
    
    if( p_x >= m_rectangle.GetX() && p_x <= m_rectangle.GetX() + m_rectangle.GetW() && p_y >=m_rectangle.GetY() && p_y <= m_rectangle.GetY() + m_rectangle.GetH()){
        m_pressed = true;
        m_mouseClickedDown = true;
        m_timeClickedDown = SDL_GetTicks();
        if (m_command) {
            m_command->execute();
        }
        else if(m_function){
            m_function();
        }
        return true;
    }
    else{
        return false;
    }
    
    return false;
}

/** Checks whether the button was clicked
 *
 *
 *  @param p_x The x coordinate of the mouse click
 *  @param p_y The y coordinate of the mouse click
 *
 *  @return bool Returns true if button was clicked up
 */
bool gui::Button::CheckMouseClickUp(int p_x, int p_y){
    
    m_mouseClickedDown = false;
    if(SDL_GetTicks() - m_timeClickedDown > 500){
        m_pressed = false;
    }
    return false;
}

/** Draws the button based on its current state
 *
 *  @param p_window Pointer to the game window object
 */
void gui::Button::Draw(n8::Window* p_window){
    if (!m_style) {
        exit(EXIT_FAILURE);
    }
    
    SDL_Renderer* renderer= p_window->GetRenderer();
    if(m_pressed){
        SDL_SetRenderDrawColor( renderer,
                               m_style->GetColor(Style::EStyleColor::Pressed).GetR(),
                               m_style->GetColor(Style::EStyleColor::Pressed).GetG(),
                               m_style->GetColor(Style::EStyleColor::Pressed).GetB(),
                               m_style->GetColor(Style::EStyleColor::Pressed).GetA()
                               );
        SDL_RenderFillRect( renderer, m_rectangle.GetRect() );
    }
    else if (m_hover) {
        SDL_SetRenderDrawColor( renderer,
                               m_style->GetColor(Style::EStyleColor::Hover).GetR(),
                               m_style->GetColor(Style::EStyleColor::Hover).GetG(),
                               m_style->GetColor(Style::EStyleColor::Hover).GetB(),
                               m_style->GetColor(Style::EStyleColor::Hover).GetA()
                               );
        SDL_RenderFillRect( renderer, m_rectangle.GetRect() );
    }
    else{
        SDL_SetRenderDrawColor( renderer,
                               m_style->GetColor(Style::EStyleColor::Button).GetR(),
                               m_style->GetColor(Style::EStyleColor::Button).GetG(),
                               m_style->GetColor(Style::EStyleColor::Button).GetB(),
                               m_style->GetColor(Style::EStyleColor::Button).GetA()
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