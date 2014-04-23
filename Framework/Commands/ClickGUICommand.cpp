/*
 *  ClickGUICommand.cpp
 *  n8
 *
 *  Created by Nate Ebel on 4/23/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#include "ClickGUICommand.h"

n8::ClickGUICommand::ClickGUICommand(gui::GUI* p_gui) : m_gui(p_gui){
    
}

n8::ClickGUICommand::~ClickGUICommand(){
    
}

bool n8::ClickGUICommand::execute(){
    return false;
}


bool n8::ClickGUICommand::execute(int p_x, int p_y){
    return m_gui->CheckClick(p_x,p_y);
}