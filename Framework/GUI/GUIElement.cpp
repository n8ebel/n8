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


gui::GUIElement::GUIElement() : m_style(nullptr), m_texture(nullptr),
    m_rectangle(0,0,1,1),
    m_x(0),
    m_y(0),
    m_w(1),
    m_h(1),
    m_built(false)
{

}

gui::GUIElement::GUIElement(int p_x, int p_y, int p_w, int p_h) :
                                                                    m_style(nullptr),
                                                                    m_rectangle(p_x,p_y,p_w,p_h),
                                                                    m_x(p_x),
                                                                    m_y(p_y),
                                                                    m_w(p_w),
                                                                    m_h(p_h)
{
    m_texture = nullptr;
}

gui::GUIElement::~GUIElement(){
    
}

void gui::GUIElement::OffsetPosition(int p_x, int p_y){
    m_x += p_x;
    m_y += p_y;
    m_rectangle.Offset(p_x, p_y);
}

void gui::GUIElement::SetStyle(Style* p_style){
    m_style = p_style;
}