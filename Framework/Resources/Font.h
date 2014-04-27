/*
 * Font.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            4/17/14
 * Organization:    n8Tech
 *
 */

#ifndef FONT_H
#define FONT_H

#include <iostream>
#include <string>

#include "Resource.h"

namespace n8{
    
    class Font : public Resource{
    public:
        Font(std::string p_id, TTF_Font* p_ttfFont);
        ~Font();
        
    private:
        
        TTF_Font* m_font;
        
        friend class RenderService;
    };
    
}

#endif /* defined(FONT_H) */