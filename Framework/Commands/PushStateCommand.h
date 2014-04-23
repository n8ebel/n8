/*
 *  PushStateCommand.h
 *  n8
 *
 *  Created by Nate Ebel on 4/12/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#ifndef PUSH_STATE_COMMAND_H
#define PUSH_STATE_COMMAND_H

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
    virtual bool execute();
    
private:
    EState::Values m_state;
    
    
};

}



#endif /* defined(__DevApp__PopStateCommand__) */
