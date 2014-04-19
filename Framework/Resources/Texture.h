/*
 * Texture.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            4/18/14
 * Organization:    n8Tech
 *
 */

#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>

#include "Resource.h"

namespace n8{
    
    /** An object to hold an optimzed SDL_Surface image and provide access to it **/
    class Texture :public Resource{
    public:
        ~Texture();
        Texture(std::string p_id, SDL_Texture* p_img, int p_w, int p_h);
        
    private:
        
        SDL_Texture* m_texture;  /** < The texture that can be rendered to the screen  **/
        
        int m_width;
        int m_height;
        
        friend class RenderService;
    };
    
}
#endif (TEXTURE_H)
