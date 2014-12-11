/*
 *  AudioService.h
 *  goobar
 *
 *  Created by Nate Ebel on 4/18/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#ifndef AUDIO_SERVICE
#define AUDIO_SERVICE

#include <iostream>
#include <assert.h>
#include <string>

#include "Log.h"
#include "Service.h"
#include "Music.h"
#include "SoundEffect.h"
#include "PlayMusicCommand.h"
#include "PlaySoundEffectCommand.h"

namespace n8 {
    /** \class AudioService
     *  \brief Handles audio playing
     *
     *  This class handles playing of game audio by providing
     *   playback methods for both Music and SoundEffects.
     *
     *  @see Music, @see SoundEffect
     */
    class AudioService : public Service{
    public:
        AudioService(std::shared_ptr<n8::Game>);
        ~AudioService();
        
        void OnNotify(std::shared_ptr<Event>) override;
        
        void PlayMusic(const std::shared_ptr<Music> p_music);
        void PauseMusic();
        void Unpause();
        void StopMusic();
        
        void PlaySoundEffect(const std::shared_ptr<SoundEffect> p_soundEffect);
        
    private:
        bool m_musicPlaying; /**< Indicates if music is currently being played **/
        bool m_musicPaused; /**< Indicates if music is currently paused **/
        
    };
}

#endif /* defined(AUDIO_SERVICE) */