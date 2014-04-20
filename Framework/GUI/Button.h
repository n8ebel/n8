/*
 * Button.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            4/20/14
 * Organization:    n8Tech
 *
 */

#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>

#include <SDL2/SDL.h>
#include "SDL2_image/SDL_image.h"
#include "SDL2_ttf/SDL_ttf.h"

#include "Window.h"

namespace gui{

class Button{
public:
    Button(int p_x, int p_y, int p_w, int p_h);
    ~Button();
    
    void Draw(n8::Window*);
    void CheckMouse();
    
private:
    SDL_Texture* m_texture;
    
    
    
    int m_x;
    int m_y;
    int m_h;
    int m_w;
    
    SDL_Rect m_buttonShape;
    
    bool m_hover;
};
    
}

#endif /* defined(BUTTON_H) */
