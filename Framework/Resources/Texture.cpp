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

n8::Texture::Texture(std::string p_id, SDL_Texture* p_texture, int p_w, int p_h): Resource(p_id){
    m_texture = p_texture;
    m_width = p_w;
    m_height = p_h;
}

n8::Texture::~Texture(){
    SDL_DestroyTexture(m_texture);
    m_texture = nullptr;
}