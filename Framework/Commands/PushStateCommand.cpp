/*
 *  PushStateCommand.cpp
 *  n8
 *
 *  Created by Nate Ebel on 4/12/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#include "PushStateCommand.h"

/** Constructor
 *  Saves the desired enumerated state identifier to push onto the stack
 *
 *  @param state The state identifer to push onto the stack
 */
n8::PushStateCommand::PushStateCommand(EState::Values state) : m_state(state){
    
}

/** Destructor
 */
n8::PushStateCommand::~PushStateCommand(){
    
}

/** Pushes a state onto the game's state stack using the saved state identifier
 */
bool n8::PushStateCommand::execute(){
    
    static_cast<n8::StateManagerService*>(n8::ServiceManager::GetInstance()->GetService(EService::StateManager))->PushState(m_state);
    
    return true;
}
