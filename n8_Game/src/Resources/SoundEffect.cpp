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

/** Constructor
 *  Initializes parent class {@link Resource}
 *  Sets pointer to loaded sound effect data
 *
 *  @param p_id The identifier of the resource
 *  @param p_mixChunk Pointer to the loaded sound effect data 
 */
n8::SoundEffect::SoundEffect(std::string p_id, Mix_Chunk* p_mixChunk) : Resource(p_id){
    
    m_soundEffect = p_mixChunk;
    
}

/** Destructor
 *  Frees the loaded sound effect data
 */
n8::SoundEffect::~SoundEffect(){
    Mix_FreeChunk(m_soundEffect);
    m_soundEffect = nullptr;
}