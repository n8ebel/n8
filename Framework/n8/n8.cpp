//
//  n8.cpp
//  DevApp
//
//  Created by Nate Ebel on 3/25/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#include "n8.h"


void n8::n8::Init(){
    SDL_Init( SDL_INIT_EVERYTHING );
}

void n8::n8::Shutdown(){
    SDL_Quit();
}