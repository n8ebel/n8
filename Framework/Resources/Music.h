/*
 * Music.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            4/17/14
 * Organization:    n8Tech
 *
 */

#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include <string>

#include "Resource.h"

namespace n8{
    
    class Music : public Resource{
    public:
        Music(std::string p_id, Mix_Music* p_mixMusic);
        ~Music();
        
    private:
        
        Mix_Music* m_music;
        
        friend class AudioService;
    };
    
}

#endif /* defined(MUSIC_H) */