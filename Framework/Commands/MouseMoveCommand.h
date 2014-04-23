/*
 *  MouseMoveCommand.h
 *  n8
 *
 *  Created by Nate Ebel on 4/12/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#ifndef MOUSE_MOVE_COMMAND_H
#define MOUSE_MOVE_COMMAND_H

#include <iostream>

#include "Command.h"
#include "Button.h"

namespace n8{
    
    class MouseMoveCommand : public Command {
        
    public:
        MouseMoveCommand(gui::Button*);
        
        ~MouseMoveCommand();
        virtual bool execute();
        
    private:
        gui::Button* m_button;
        
    };
    
}



#endif /* defined(MOUSE_MOVE_COMMAND_H) */