/*
 *  MouseClickCommand.cpp
 *  n8
 *
 *  Created by Nate Ebel on 4/22/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#include "MouseClickCommand.h"

n8::MouseClickCommand::MouseClickCommand(std::vector<PositionCommand*>& p_commandList){
    m_commands = p_commandList;
}

n8::MouseClickCommand::~MouseClickCommand(){
    
}

bool n8::MouseClickCommand::execute(){
    return false;
}

bool n8::MouseClickCommand::execute(int p_x, int p_y){
    
        for (int i = 0; i < m_commands.size(); i++) {
            if( m_commands[i] != NULL){
                if ( m_commands[i]->execute(p_x, p_y) ) {
                    return true;
                }
            }
        }
    
    
    return false;
}