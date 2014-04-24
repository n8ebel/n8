//
//  GUIElement.cpp
//  DevApp
//
//  Created by Nate Ebel on 4/21/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#include "GUIElement.h"


gui::GUIElement::GUIElement(int p_x, int p_y, int p_w, int p_h) :   m_x(p_x),
                                                                    m_y(p_y),
                                                                    m_w(p_w),
                                                                    m_h(p_h)
{
    m_shape.x = m_x;
    m_shape.y = m_y;
    m_shape.w = m_w;
    m_shape.h = m_h;
    
}

gui::GUIElement::~GUIElement(){
    
}

void gui::GUIElement::OffsetPosition(int p_x, int p_y){
    m_x += p_x;
    m_y += p_y;
}