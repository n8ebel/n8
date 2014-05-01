//
//  PositionCommand.h
//  DevApp
//
//  Created by Nate Ebel on 4/13/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#ifndef POSITION_COMMAND_H
#define POSITION_COMMAND_H

#include "Command.h"

namespace n8{
    
    
    class PositionCommand : public Command
    {
    public:
        virtual ~PositionCommand() {}
        virtual bool execute() = 0;
        virtual bool execute(int p_x, int p_y) = 0;
    };
    
}


#endif