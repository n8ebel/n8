/*
 *  MouseClickCommand.cpp
 *  n8
 *
 *  Created by Nate Ebel on 4/22/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#include "MouseClickCommand.h"

n8::MouseClickCommand::MouseClickCommand(std::vector<Command*>& p_commandList){
    m_commands = p_commandList;
    m_command = NULL;
    std::cout << "Size of m_commands = " << m_commands.size() << std::endl;
}

n8::MouseClickCommand::MouseClickCommand(Command* p_command) : m_command(p_command), m_commands(NULL){
    
}

n8::MouseClickCommand::~MouseClickCommand(){
    
}

bool n8::MouseClickCommand::execute(){
    if (m_command) {
        m_command->execute();
    }
    else{
        for (int i = 0; i < m_commands.size(); i++) {
            if( m_commands[i] != NULL){
                if ( m_commands[i]->execute() ) {
                    break;
                }
            }
        }
    }
    
    return true;
}