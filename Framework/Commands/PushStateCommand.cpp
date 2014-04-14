/*
 *  PushStateCommand.cpp
 *  n8
 *
 *  Created by Nate Ebel on 4/12/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#include "PushStateCommand.h"

n8::PushStateCommand::PushStateCommand(EState::Values state) : m_state(state){
    
}

n8::PushStateCommand::~PushStateCommand(){
    
}

void n8::PushStateCommand::execute(){
    
    static_cast<n8::StateManagerService*>(n8::ServiceManager::GetInstance()->GetService(EService::StateManager))->PushState(m_state);
    
}
