/*
 * SoundEffect.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            4/14/14
 * Organization:    n8Tech
 *
 */

#include "SoundEffect.h"

n8::SoundEffect::SoundEffect(std::string p_id, Mix_Chunk* p_mixChunk) : Resource(p_id){
    
    m_soundEffect = p_mixChunk;
    
}

n8::SoundEffect::~SoundEffect(){
    Mix_FreeChunk(m_soundEffect);
    m_soundEffect = nullptr;
}