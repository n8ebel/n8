//
//  n8.h
//  DevApp
//
//  Created by Nate Ebel on 3/25/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#ifndef __DevApp__n8__
#define __DevApp__n8__

#include <iostream>

#include <SDL2/SDL.h>
#include "SDL2_image/SDL_image.h"
#include "SDL2_mixer/SDL_mixer.h"
#include "SDL2_ttf/SDL_ttf.h"

namespace n8 {
    class n8{
        static void Init();
        static void Shutdown();
    };
}

#endif /* defined(__DevApp__n8__) */
