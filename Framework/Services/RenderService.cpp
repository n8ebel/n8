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
}

n8::RenderService::~RenderService(){
    m_gameWindow = NULL;
}

void n8::RenderService::OnNotify(Event* event){
    
}

void n8::RenderService::DrawSprite(Sprite* p_sprite, int p_x, int p_y){
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