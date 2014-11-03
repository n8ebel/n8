/*
 *  RenderService.cpp
 *  goobar
 *
 *  Created by Nate Ebel on 4/18/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#include "RenderService.h"

#define TAG "RenderService"

/** Constructor
 *
 *  @param p_window Pointer the the game's window object
 */
n8::RenderService::RenderService(Game* game, Window* p_window) : Service(game){
    m_gameWindow = p_window;
    m_renderMode = ETexture;
}

/** Destructor */
n8::RenderService::~RenderService(){
    Log::Info(TAG, "Destructor");
    m_gameWindow = nullptr;
}

/**
 *  Sets the current render mode to control how drawing and background coloring is handled
 *
 *  @param p_mode The render mode specified by the user
 *
 *  @see ERenderMode
 */
void n8::RenderService::SetRenderMode(n8::RenderService::ERenderMode p_mode){
    m_renderMode = p_mode;
}

void n8::RenderService::OnNotify(Event* event){
    
}

/**
 *  Draws a sprite to the window surface at a specified location
 *
 *  @param p_sprite The sprite to draw
 *  @param p_x The x position where sprite will be drawn
 *  @param p_h The y position where sprite will be drawn
 *
 *  @see Sprite
 */
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

/**
 *  Renders a texture to the window renderer at a specified location
 *
 *  @param p_texture The texture to draw
 *  @param p_x The x position where sprite will be drawn
 *  @param p_h The y position where sprite will be drawn
 *
 *  @see Texture
 */
void n8::RenderService::Draw(n8::Texture* p_texture, int p_x, int p_y){
    
    SDL_Rect dest;
    
    dest.x = p_x;
    dest.y = p_y;
    dest.w = p_texture->m_width;
    dest.h = p_texture->m_height;
    
    //Render texture to screen
    SDL_RenderCopy( m_gameWindow->GetRenderer(), p_texture->m_texture, NULL, &dest );
}

/**
 *  Draws a texture to the window renderer at a specified location with a specified width and height
 *
 *  @param p_texture The texture to draw
 *  @param p_x The x position where sprite will be drawn
 *  @param p_h The y position where sprite will be drawn
 *  @param p_w The width of screen renderer to fill with texture
 *  @param p_h The height of screen renderer to fill with texture
 *
 *  @see Texture
 */
void n8::RenderService::Draw(n8::Texture* p_texture, int p_x, int p_y, int p_w, int p_h){
    
    SDL_Rect dest;
    
    dest.x = p_x;
    dest.y = p_y;
    dest.w = p_w;
    dest.h = p_h;
    
    //Render texture to screen
    SDL_RenderCopy( m_gameWindow->GetRenderer(), p_texture->m_texture, NULL, &dest );
}

void n8::RenderService::DrawText(std::string p_text, Font* p_font, EColor p_color,int p_x, int p_y){
    
    if (p_font != nullptr) {
        SDL_Color textColor;
        LTexture textTexture;
        
        if (p_color == EColor::Black) {
            textColor.r = 0;
            textColor.g = 0;
            textColor.b = 0;
            textColor.a = 255;
        }
        else{
            textColor.r = 255;
            textColor.g = 255;
            textColor.b = 255;
            textColor.a = 255;
            
        }
        
        if( textTexture.loadFromRenderedText( m_gameWindow->GetRenderer(), p_font->m_font, p_text.c_str(), textColor ) ){
        
            textTexture.render(m_gameWindow->GetRenderer(), p_x, p_y);
        }
        else{
            Log::Debug(TAG, "Couldn't load text texture");
        }
    }
    else{
        Log::Debug(TAG, "Font was null");
    }
    
}

/**
 *  Sets the color to use when drawing shapes or coloring the background.
 *  If in texture rendering mode it sets RenderDrawColor
 *
 *  @param p_r The red value
 *  @param p_g The green value
 *  @param p_b The blue value
 *  @param p_a The alpha value
 */
void n8::RenderService::SetDrawingColor(int p_r, int p_g, int p_b, int p_a){
    m_red = p_r;
    m_green = p_g;
    m_blue = p_b;
    m_alpha = p_a;
    
    if(m_renderMode == ETexture){
        SDL_SetRenderDrawColor(m_gameWindow->GetRenderer(), m_red , m_green, m_blue, m_alpha);
    }
}

/**
 *  Colors the background to the stored drawing color.
 *  Coloring is done differently for each rendering mode.
 */
void n8::RenderService::ColorBackground(){
    if (m_renderMode == ESprite) {
        SDL_FillRect(m_gameWindow->GetSurface(), NULL, SDL_MapRGBA(SDL_GetWindowSurface(m_gameWindow->GetWindow())->format, m_red,m_green,m_blue,m_alpha));
    }
    else{
        SDL_RenderClear(m_gameWindow->GetRenderer());
    }
}

/** 
 *  Posts all drawn sprites or textures to the screen
 */
void n8::RenderService::PostToScreen(){
    if (m_renderMode == ESprite) {
        SDL_UpdateWindowSurface( m_gameWindow->GetWindow() );
    }
    else{
        SDL_RenderPresent(m_gameWindow->GetRenderer());
    }
}