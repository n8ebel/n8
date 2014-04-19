//
//  AudioService.cpp
//  DevApp
//
//  Created by Nate Ebel on 4/19/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#include "AudioService.h"

#define TAG "AudioService"

/** Constructor */
n8::AudioService::AudioService(){
    m_musicPlaying = false;
    m_musicPaused = false;
}

/** Destructor */
n8::AudioService::~AudioService(){
    
}

void n8::AudioService::OnNotify(Event* p_event){
    
}

/** 
 *  Plays a specified Music resource
 *
 *  @param p_music The Music resource to play
 *
 *  @see Music
 */
void n8::AudioService::PlayMusic(Music* p_music){
    if( Mix_PlayMusic(p_music->m_music, -1) == 0 ){
        m_musicPlaying = true;
    }
    else{
        std::string msg("Error playing music: %s\n", Mix_GetError());
        Log::Error(TAG, msg);
    }
}

/**
 *  Pauses the currently playing music if there is any
 */
void n8::AudioService::PauseMusic(){
    if(!m_musicPaused){
        Mix_PauseMusic();
    }
}

/**
 *  Resumes playing music if any is paused
 */
void n8::AudioService::Unpause(){
    if(m_musicPaused){
        Mix_ResumeMusic();
    }
}

/**
 *  Stops playing music if any is currently playing
 */
void n8::AudioService::StopMusic(){
    if (m_musicPlaying) {
        Mix_HaltMusic();
        m_musicPlaying = false;
        m_musicPaused = false;
    }
}

/**
 *  Plays a specified sound effect
 *
 *  @param p_soundEffect The sound effect to play
 *
 *  @see SoundEffect
 */
void n8::AudioService::PlaySoundEffect(SoundEffect* p_soundEffect){
    if( Mix_PlayChannel(-1, p_soundEffect->m_soundEffect, 0) != -1 ){
        
    }
    else{
        std::string msg("Error playing sound effect: %s\n", Mix_GetError());
        Log::Error(TAG, msg);
    }
}


