/*
 *  PopStateCommand.h
 *  n8
 *
 *  Created by Nate Ebel on 4/12/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#ifndef __DevApp__PopStateCommand__
#define __DevApp__PopStateCommand__

#include <iostream>

#include "Command.h"
#include "StateManagerService.h"
#include "ServiceManager.h"

namespace n8{

    class PopStateCommand : public Command {
    
public:
    PopStateCommand();
    
    ~PopStateCommand();
    virtual void execute();
    
private:
    
    
};

}



#endif /* defined(__DevApp__PopStateCommand__) */
