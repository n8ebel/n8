//
//  LTexture.cpp
//  DevApp
//
//  Created by Nate Ebel on 4/24/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#include "LTexture.h"

LTexture::LTexture()
{
    //Initialize
    mTexture = nullptr;
    mWidth = 0;
    mHeight = 0;
}

LTexture::~LTexture()
{
    //Deallocate
    free();
}

bool LTexture::loadFromFile( SDL_Renderer* p_renderer,std::string path )
{
    //Get rid of preexisting texture
    free();
    
    //The final texture
    SDL_Texture* newTexture = nullptr;
    
    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == nullptr )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Color key image
        SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );
        
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( p_renderer, loadedSurface );
        if( newTexture == nullptr )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }
        else
        {
            //Get image dimensions
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
        }
        
        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }
    
    //Return success
    mTexture = newTexture;
    return mTexture != nullptr;
}

void LTexture::free()
{
    //Free texture if it exists
    if( mTexture != nullptr )
    {
        SDL_DestroyTexture( mTexture );
        mTexture = nullptr;
        mWidth = 0;
        mHeight = 0;
    }
}


int LTexture::getWidth() const {
    return mWidth;
}

int LTexture::getHeight() const {
    return mHeight;
}

void LTexture::render( SDL_Renderer* p_renderer,int x, int y ) const{
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, mWidth, mHeight };
    SDL_RenderCopy( p_renderer, mTexture, NULL, &renderQuad );
}

bool LTexture::loadFromRenderedText( SDL_Renderer* p_renderer,TTF_Font* p_font, std::string textureText, SDL_Color textColor )
{
    //Get rid of preexisting texture
    free();
    
    //Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid( p_font, textureText.c_str(), textColor );
    if( textSurface == nullptr )
    {
        printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
        if(p_font == nullptr)
            printf( "   font was null");
        else
            printf( "   font wasn't null");
        
        printf( "   texture text was: %s", textureText.c_str());
        printf( "   texture color was %i,%i,%i", textColor.r, textColor.g, textColor.b);
    }
    else
    {
        //Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface( p_renderer, textSurface );
        if( mTexture == nullptr )
        {
            printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
        }
        else
        {
            //Get image dimensions
            mWidth = textSurface->w;
            mHeight = textSurface->h;
        }
        
        //Get rid of old surface
        SDL_FreeSurface( textSurface );
    }
    
    //Return success
    return mTexture != nullptr;
}

bool LTexture::HasTexture() const{
    if (mTexture) {
        return true;
    }
    else{
        return false;
    }
}