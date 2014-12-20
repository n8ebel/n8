/*
 * Texture.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            4/18/14
 * Organization:    n8Tech
 *
 */

#include "Texture.h"

n8::Texture::Texture() : Resource("") { }

/** Constructor
 *  Initializes parent class Resource.
 *
 *  @param p_id The string identifier of the resource.
 *  @param p_texture A pointer to a SDL_Texture object
 *  @param p_w The width of the created texture object
 *  @param p_h The height of the created texture object
 */
n8::Texture::Texture(std::string p_id, SDL_Texture* p_texture, int p_w, int p_h) : Resource(p_id),
    m_texture(p_texture),
    m_width(p_w),
    m_height(p_h)
{
    
}

n8::Texture::Texture(std::string p_id, SDL_Renderer* p_renderer,TTF_Font* p_font, std::string textureText, SDL_Color textColor ) : Resource(p_id)
{
    
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
        m_texture = SDL_CreateTextureFromSurface( p_renderer, textSurface );
        if( m_texture == nullptr )
        {
            printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
        }
        else
        {
            //Get image dimensions
            m_width = textSurface->w;
            m_height = textSurface->h;
        }
        
        //Get rid of old surface
        SDL_FreeSurface( textSurface );
    }
}

/** Destructor
 *  Destroys the texture
 */
n8::Texture::~Texture(){
    SDL_DestroyTexture(m_texture);
    m_texture = nullptr;
}

void n8::Texture::Render(SDL_Renderer * p_renderer, int p_x, int p_y) const{
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { p_x, p_y, m_width, m_height };
    SDL_RenderCopy( p_renderer, m_texture, NULL, &renderQuad );
}

SDL_Texture* n8::Texture::Get_SDLTexture() const{
    return m_texture;
}