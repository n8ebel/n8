/*
 *  Timer.h
 *  goobar
 *
 *  Created by Nate Ebel on 3/18/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#ifndef TIMER_H
#define TIMER_H

#include <iostream>

#include "/Library/Frameworks/SDL2.framework/Versions/A/Headers/SDL.h"

namespace n8{
    
class Timer{
public:
    Timer();
    ~Timer();
    
    void UpdateCurrentTime();
    void SyncGame(unsigned);
    
    unsigned int GetElapsedTime() const;
    unsigned int GetTime() const;
    
private:
    Uint32 m_startTime;  /** < Time when the timer was created */
    mutable Uint32 m_currentTime;  /** < current game time **/
};

}

#endif /* defined(TIMER_H) */
