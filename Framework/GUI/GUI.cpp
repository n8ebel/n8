//
//  GUI.cpp
//  DevApp
//
//  Created by Nate Ebel on 4/21/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#include "GUI.h"

gui::GUI::GUI(){
    
}

gui::GUI::~GUI(){
    
}

void gui::GUI::CheckMouse(){
    for (int i = 0; i < m_widgets.size(); i++) {
        m_widgets[i]->CheckMouse();
    }
}