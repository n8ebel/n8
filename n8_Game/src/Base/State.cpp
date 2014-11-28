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

n8::State::State(std::shared_ptr<n8::Game> game){
    m_game = game;
    m_gui = std::make_shared<gui::GUI>(const_cast<n8::Window*>(game->getRenderService()->GetWindow()));
}

n8::State::~State(){ m_game = nullptr; }

const ID& n8::State::GetId() const { return *m_id; };

const std::shared_ptr<gui::GUI> n8::State::GetGUI() const { return m_gui; }

void n8::State::Update(Uint32 currentTime){
    m_gui->Update(currentTime);
}

void n8::State::Render(n8::Window *window){
    m_gui->Draw(window);
    m_game->getRenderService()->PostToScreen();
}