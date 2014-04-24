/*
 *  ClickGUICommand.cpp
 *  n8
 *
 *  Created by Nate Ebel on 4/23/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#include "ClickDownGUICommand.h"

n8::ClickDownGUICommand::ClickDownGUICommand(gui::GUI* p_gui) : m_gui(p_gui){
    
}

n8::ClickDownGUICommand::~ClickDownGUICommand(){
    
}

bool n8::ClickDownGUICommand::execute(){
    return false;
}


bool n8::ClickDownGUICommand::execute(int p_x, int p_y){
    return m_gui->CheckClickDown(p_x,p_y);
}