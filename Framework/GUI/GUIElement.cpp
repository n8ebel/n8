//
//  GUIElement.cpp
//  DevApp
//
//  Created by Nate Ebel on 4/21/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#include "GUIElement.h"


gui::GUIElement::GUIElement(){
    
}

gui::GUIElement::~GUIElement(){
    
}

void gui::GUIElement::OffsetPosition(int p_x, int p_y){
    m_x += p_x;
    m_y += p_y;
}