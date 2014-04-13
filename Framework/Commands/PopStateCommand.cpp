//
//  PopStateCommand.cpp
//  DevApp
//
//  Created by Nate Ebel on 4/13/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#include "PopStateCommand.h"

n8::PopStateCommand::PopStateCommand(){
    
}

n8::PopStateCommand::~PopStateCommand(){
    
}

void n8::PopStateCommand::execute(){
    
    static_cast<n8::StateManagerService*>(n8::ServiceManager::GetInstance()->GetService(EService::StateManager))->PopState();
    
}
