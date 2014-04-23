/*
 *  MouseClickCommand.h
 *  n8
 *
 *  Created by Nate Ebel on 4/22/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#ifndef MOUSE_CLICK_COMMAND_H
#define MOUSE_CLICK_COMMAND_H

#include <iostream>
#include <vector>

#include "Command.h"
#include "Button.h"

namespace n8{
    
    class MouseClickCommand : public Command {
        
    public:
        MouseClickCommand(std::vector<Command*>&);
        MouseClickCommand(Command*);
        
        ~MouseClickCommand();
        virtual bool execute();
        
    private:
        std::vector<Command*> m_commands;
        Command* m_command;
        
    };
    
}



#endif /* defined(MOUSE_MOVE_COMMAND_H) */