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

#include "PositionCommand.h"
#include "Button.h"

namespace n8{
    
    class MouseClickCommand : public PositionCommand {
        
    public:
        MouseClickCommand(std::vector<PositionCommand*>&);
        
        ~MouseClickCommand();
        virtual bool execute();
        bool execute(int p_x, int p_y);
        
    private:
        std::vector<PositionCommand*> m_commands;
        
    };
    
}



#endif /* defined(MOUSE_MOVE_COMMAND_H) */