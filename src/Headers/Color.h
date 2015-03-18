/*
 *  Color.h
 *  goobar
 *
 *  Created by Nate Ebel on 4/28/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#ifndef COLOR_H
#define COLOR_H

#include <iostream>

#include "/Library/Frameworks/SDL2.framework/Versions/A/Headers/SDL.h"

/** \class Color
 *  \brief Wraps SDL_Color functionality
 *
 *  Stores color information used for rendering text and primatives
 */
namespace n8{
    class Color{
    public:
        Color();
        Color(int p_r, int p_g, int p_b);
        Color(int p_r, int p_g, int p_b, int p_a);
        
        Color& operator = (const Color&);
        
        void Set(int p_r, int p_g, int p_b);
        void Set(int p_r, int p_g, int p_b, int p_a);
        
        void SetR(int p_r);
        void SetG(int p_g);
        void SetB(int p_b);
        void SetA(int p_a);
        
        int GetR() const;
        int GetG() const;
        int GetB() const;
        int GetA() const;
        
        SDL_Color GetColor();
        
    private:
        SDL_Color m_color; /** < SDL_Color object wrapped by this class.  Used for rendering operations. **/
        
    };
    
}

#endif /* defined(COLOR_H) */
