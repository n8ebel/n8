/*
 * Audio.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            4/14/14
 * Organization:    n8Tech
 *
 */

#ifndef AUDIO_H
#define AUDIO_H

#include <iostream>
#include <string>

#include "Resource.h"

namespace n8{
    
class Audio : public Resource{
public:
    Audio(std::string p_id);
    ~Audio();
    
private:
    
    friend class AudioService;
};
    
}

#endif /* defined(AUDIO_H) */
