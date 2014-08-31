/*
 *  PlaySoundEffectCommand.cpp
 *  n8
 *
 *  Created by Nate Ebel on 4/21/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#include "PlaySoundEffectCommand.h"

n8::PlaySoundEffectCommand::PlaySoundEffectCommand(std::string p_effectID) : m_effectID(p_effectID){
    
}

n8::PlaySoundEffectCommand::~PlaySoundEffectCommand(){
    
}

bool n8::PlaySoundEffectCommand::execute(){
    static_cast<n8::AudioService*>(n8::ServiceManager::GetInstance()->GetService(ServiceManager::AUDIO))->PlaySoundEffect(static_cast<SoundEffect*>(static_cast<n8::ResourceManager*>(n8::ServiceManager::GetInstance()->GetService(ServiceManager::RESOURCES))->GetResource(m_effectID)));
    
    return true;
}