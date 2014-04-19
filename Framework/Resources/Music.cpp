/*
 * Music.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            4/17/14
 * Organization:    n8Tech
 *
 */

#include "Music.h"

n8::Music::Music(std::string p_id, Mix_Music* p_mixMusic) : Resource(p_id){
    
    m_music = p_mixMusic;
    
}

n8::Music::~Music(){
    Mix_FreeMusic(m_music);
    m_music = NULL;
}