//
//  Service.cpp
//  n8_Game
//
//  Created by Nate Ebel on 11/28/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#include <stdio.h>

#include "Service.h"
#include "Game.h"

n8::Service::Service(std::shared_ptr<n8::Game> game){
    m_game = game;
}

n8::Service::~Service(){ }