/*
 *  PopStateCommand.cpp
 *  n8
 *
 *  Created by Nate Ebel on 4/12/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#include "PopStateCommand.h"

/** Constructor */
n8::PopStateCommand::PopStateCommand(){
    
}

/** Destructor */
n8::PopStateCommand::~PopStateCommand(){
    
}

/** Pops the top state off of the game's state stack */
bool n8::PopStateCommand::execute(){
    
    StateManagerService* stateManager = static_cast<n8::StateManagerService*>(n8::ServiceManager::GetInstance()->GetService(n8::ServiceManager::STATE_MANAGER));
    if(stateManager != nullptr){
        stateManager->PopState();
    }
    
    return true;
}
