//
//  PopStateCommand.h
//  DevApp
//
//  Created by Nate Ebel on 4/13/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#ifndef __DevApp__PopStateCommand__
#define __DevApp__PopStateCommand__

#include <iostream>

#include "Command.h"
#include "StateManagerService.h"
#include "ServiceManager.h"
#include "Enums.h"

namespace n8{

class PushStateCommand : public Command {
    
public:
    PushStateCommand(EState::Values);
    
    ~PushStateCommand();
    virtual void execute();
    
private:
    EState::Values m_state;
    
    
};

}



#endif /* defined(__DevApp__PopStateCommand__) */
