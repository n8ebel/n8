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

/** Constructor
 *  Initializes parent class Resource.
 *
 *  @param p_id The string identifier of the resource.
 *  @param p_texture A pointer to a SDL_Texture object
 *  @param p_w The width of the created texture object
 *  @param p_h The height of the created texture object
 */
n8::Texture::Texture(std::string p_id, SDL_Texture* p_texture, int p_w, int p_h): Resource(p_id){
    m_texture = p_texture;
    m_width = p_w;
    m_height = p_h;
}

/** Destructor
 *  Destroys the texture
 */
n8::Texture::~Texture(){
    SDL_DestroyTexture(m_texture);
    m_texture = nullptr;
}

SDL_Texture* n8::Texture::Get_SDLTexture() const{
    return m_texture;
}