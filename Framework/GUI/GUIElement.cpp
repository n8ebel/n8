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


gui::GUIElement::GUIElement(){
    
}

gui::GUIElement::GUIElement(int p_x, int p_y, int p_w, int p_h) :
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