/*
 *  PlayMusicCommand.cpp
 *  n8
 *
 *  Created by Nate Ebel on 4/21/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#include "PlayMusicCommand.h"

n8::PlayMusicCommand::PlayMusicCommand(std::string p_musID) : m_musicID(p_musID){
    
}

n8::PlayMusicCommand::~PlayMusicCommand(){
    
}

bool n8::PlayMusicCommand::execute(){
    static_cast<n8::AudioService*>(n8::ServiceManager::GetInstance()->GetService(ServiceManager::AUDIO))->PlayMusic(static_cast<Music*>(static_cast<n8::ResourceManager*>(n8::ServiceManager::GetInstance()->GetService(ServiceManager::RESOURCES))->GetResource(m_musicID)));
    
    return true;
}