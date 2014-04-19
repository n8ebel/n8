//
//  Command.h
//  DevApp
//
//  Created by Nate Ebel on 4/13/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#ifndef COMMAND_H
#define COMMAND_H

#include "Event.h"

namespace n8{
    

class Command
{
public:
    virtual ~Command() {}
    virtual void execute() = 0;
};
    
}


#endif
