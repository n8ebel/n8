//
//  State.cpp
//  n8_Game
//
//  Created by Nate Ebel on 10/30/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#include <stdio.h>

#include "Game.h"
#include "State.h"

n8::State::State(n8::Game* game){
    m_game = game;
    m_gui = new gui::GUI(const_cast<n8::Window*>(game->getRenderService()->GetWindow()));
}

n8::State::~State(){
    m_game = nullptr;
    if (m_gui) {
        delete m_gui;
        m_gui = nullptr;
    }
}

ID n8::State::GetId() {return *m_id;};

gui::GUI* n8::State::GetGUI() { return m_gui; }