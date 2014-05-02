/*
 * GUIElement.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            4/20/14
 * Organization:    n8Tech
 *
 */

#include "GUIElement.h"


gui::GUIElement::GUIElement() : m_style(nullptr),
                                m_texture(nullptr),
                                m_rectangle(0,0,1,1),
                                m_built(false)
{

}

gui::GUIElement::GUIElement(int p_x, int p_y, int p_w, int p_h) :
                                                                    m_style(nullptr),
                                                                    m_rectangle(p_x,p_y,p_w,p_h),
                                                                    m_texture(nullptr)
{
    
}

gui::GUIElement::~GUIElement(){
    
}

/** Moves an element to the new specified position.
 *
 *  @param p_x The new x position of the element
 *  @param p_y The new y position of the element
 */
void gui::GUIElement::ChangePosition(int p_x, int p_y){
    m_rectangle.Reposition(p_x, p_y);
}

/** Moves an element by the specified amount.
 *
 *  @param p_xOffset The amount to move the element in the x direction.
 *  @param p_yOffset The amount to move the element in the y direction.
 */
void gui::GUIElement::OffsetPosition(int p_xOffset, int p_yOffset){
    m_rectangle.Offset(p_xOffset, p_yOffset);
}

/** Sets the style pointer of the element.
 *
 *  @param p_style A pointer to the new sytle object for the element.
 */
void gui::GUIElement::SetStyle(Style* p_style){
    m_style = p_style;
}

/** Gets a pointer to the style object of the element.
 *
 *  @return m_style The style object pointer
 */
gui::Style* gui::GUIElement::GetStyle() const{
    return m_style;
}