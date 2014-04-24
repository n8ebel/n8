/*
 *  ClickUpGUICommand.cpp
 *  n8
 *
 *  Created by Nate Ebel on 4/23/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#include "ClickUpGUICommand.h"

n8::ClickUpGUICommand::ClickUpGUICommand(gui::GUI* p_gui) : m_gui(p_gui){
    
}

n8::ClickUpGUICommand::~ClickUpGUICommand(){
    
}

bool n8::ClickUpGUICommand::execute(){
    return false;
}


bool n8::ClickUpGUICommand::execute(int p_x, int p_y){
    return m_gui->CheckClickUp(p_x,p_y);
}