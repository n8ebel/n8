//
//  MouseMoveCommand.cpp
//  DevApp
//
//  Created by Nate Ebel on 4/20/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#include "MouseMoveCommand.h"

n8::MouseMoveCommand::MouseMoveCommand(gui::Button* p_button):m_button(p_button) {
    
}

n8::MouseMoveCommand::~MouseMoveCommand(){
    
}

void n8::MouseMoveCommand::execute(){
    m_button->CheckMouse();
    
}