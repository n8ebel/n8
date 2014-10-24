/*
 * Label.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            4/27/14
 * Organization:    n8Tech
 *
 */

#include "Label.h"

#define TAG "Label"

/** Constructor */
gui::Label::Label(std::string p_id,std::string p_text, int p_x, int p_y) : GUIElement(p_id,p_x,p_y,1,1) {
    
    m_labelText = p_text;
    m_texture = nullptr;
}

/** Destructor
 *  Destroy's label texture
 */
gui::Label::~Label(){
    if (m_texture) {
        SDL_DestroyTexture(m_texture);
        m_texture = nullptr;
    }
}

/** Builds the label.
 *  Uses the window pointer from style object to build the text texture
 */
void gui::Label::Build(n8::Window* window){
    
    
    m_built = m_textTexture.loadFromRenderedText(  window->GetRenderer(), m_style.GetFont()->GetFont(), m_labelText.c_str(), m_style.GetColor(Style::EStyleColor::Font).GetColor() );
    
    
    if (!m_built) {
        n8::Log::Error(TAG, "Label failed to build");
    }
    
    GUIElement::Build(window);
    
}

/** Draws the label element
 *
 *  @param p_window Pointer to the game window object
 */
void gui::Label::Draw(n8::Window* p_window){
   m_textTexture.render(p_window->GetRenderer(), m_rectangle.GetX(), m_rectangle.GetY());
}

/** Updates the Label
 *  Currently, nothing is updated for the label.  Can be overridden.
 *
 *  @param p_currentTime The current game time
 *
 *  @return bool True if any elements have focus
 */
bool gui::Label::Update(Uint32 p_currentTime){
    return false;
}

/** Moves the Label by the specified amount.
 *
 *  @param p_xOffset The amount to move the Label in the x direction.
 *  @param p_yOffset The amount to move the Label in the y direction.
 */
void gui::Label::OffsetPosition(int p_xOffset, int p_yOffset){
    m_rectangle.Offset(p_xOffset, p_yOffset);
}