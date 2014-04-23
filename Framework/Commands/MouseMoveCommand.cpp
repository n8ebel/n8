//
//  MouseMoveCommand.cpp
//  DevApp
//
//  Created by Nate Ebel on 4/20/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#include "MouseMoveCommand.h"

n8::MouseMoveCommand::MouseMoveCommand(gui::GUI* p_gui):m_gui(p_gui) {
    
}

n8::MouseMoveCommand::~MouseMoveCommand(){
    
}

bool n8::MouseMoveCommand::execute(){
    if (m_gui) {
        return m_gui->CheckMove();
    }
    
    return true;
}