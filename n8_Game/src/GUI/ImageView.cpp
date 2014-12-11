//
//  ImageView.cpp
//  n8_Game
//
//  Created by Nate Ebel on 11/19/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#include "ImageView.h"
#include "GUIElement.h"

gui::ImageView::ImageView(std::shared_ptr<n8::Window> p_window, std::string p_id, std::shared_ptr<n8::Texture> p_texture, int p_x, int p_y, int p_w, int p_h) : gui::GUIElement(p_window, p_id, p_x, p_y, p_w, p_h){
    m_texture = p_texture;
}

gui::ImageView::~ImageView(){
    
}

void gui::ImageView::Draw(const std::shared_ptr<n8::Window> p_window) const{
    if (m_texture == nullptr || m_texture->Get_SDLTexture() == nullptr) {
        return;
    }
    
    auto renderer = const_cast<SDL_Renderer*>(&p_window->GetRenderer());
    if (renderer == nullptr) {
        return;
    }
    
    SDL_Rect destination;
    destination.x = m_rectangle.GetX();
    destination.y = m_rectangle.GetY();
    destination.w = m_rectangle.GetW();
    destination.h = m_rectangle.GetH();
    
    SDL_RenderCopy(renderer, m_texture->Get_SDLTexture(), nullptr, &destination);
}

bool gui::ImageView::Update(Uint32 p_currentTime){
    return false;
}