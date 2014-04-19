/*
 *  RenderService.cpp
 *  goobar
 *
 *  Created by Nate Ebel on 4/18/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#include "RenderService.h"

n8::RenderService::RenderService(Window* p_window){
    m_gameWindow = p_window;
    m_renderMode = ETexture;
}

n8::RenderService::~RenderService(){
    m_gameWindow = NULL;
}

void n8::RenderService::SetRenderMode(n8::RenderService::ERenderMode p_mode){
    m_renderMode = p_mode;
}

void n8::RenderService::OnNotify(Event* event){
    
}

void n8::RenderService::Draw(Sprite* p_sprite, int p_x, int p_y){
    assert(p_sprite);
    assert(m_gameWindow->GetSurface());
    
	
	//Make a temporary rectangle to hold the offsets
    SDL_Rect offset;
    
    //Give the offsets to the rectangle
    offset.x = p_x;
    offset.y = p_y;
	
    
    //Blit the surface
    SDL_BlitSurface( p_sprite->m_image, NULL, m_gameWindow->GetSurface(), &offset );
    
}

void n8::RenderService::Draw(n8::Texture* p_texture, int p_x, int p_y){
    
    SDL_Rect dest;
    
    dest.x = p_x;
    dest.y = p_y;
    dest.w = p_texture->m_width;
    dest.h = p_texture->m_height;
    
    //Render texture to screen
    SDL_RenderCopy( m_gameWindow->GetRenderer(), p_texture->m_texture, NULL, &dest );
}

void n8::RenderService::Draw(n8::Texture* p_texture, int p_x, int p_y, int p_w, int p_h){
    
    SDL_Rect dest;
    
    dest.x = p_x;
    dest.y = p_y;
    dest.w = p_w;
    dest.h = p_h;
    
    //Render texture to screen
    SDL_RenderCopy( m_gameWindow->GetRenderer(), p_texture->m_texture, NULL, &dest );
}

void n8::RenderService::SetDrawingColor(int p_r, int p_g, int p_b, int p_a){
    m_red = p_r;
    m_green = p_g;
    m_blue = p_b;
    m_alpha = p_a;
    
    if(m_renderMode == ETexture){
        SDL_SetRenderDrawColor(m_gameWindow->GetRenderer(), m_red , m_green, m_blue, m_alpha);
    }
}

void n8::RenderService::ColorBackground(){
    if (m_renderMode == ESprite) {
        SDL_FillRect(m_gameWindow->GetSurface(), NULL, SDL_MapRGBA(SDL_GetWindowSurface(m_gameWindow->GetWindow())->format, m_red,m_green,m_blue,m_alpha));
    }
    else{
        SDL_RenderClear(m_gameWindow->GetRenderer());
    }
}

void n8::RenderService::PostToScreen(){
    if (m_renderMode == ESprite) {
        SDL_UpdateWindowSurface( m_gameWindow->GetWindow() );
    }
    else{
        SDL_RenderPresent(m_gameWindow->GetRenderer());
    }
}