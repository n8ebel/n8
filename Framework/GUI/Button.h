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
#include <string>

#include <SDL2/SDL.h>
#include "SDL2_image/SDL_image.h"
#include "SDL2_ttf/SDL_ttf.h"

#include "Window.h"
#include "Widget.h"
#include "Command.h"
#include "Log.h"

namespace gui{

    class Button : public Widget{
public:
        Button(std::string p_id, int p_x, int p_y, int p_w, int p_h, n8::Command* p_command);
    ~Button();
    
    void Draw(n8::Window*);
    virtual bool CheckMouseClick(int p_x, int p_y);
    virtual bool CheckMouseMove();
    
private:
    SDL_Texture* m_texture;
    
    
        std::string m_id;
    int m_x;
    int m_y;
    int m_h;
    int m_w;
    
    SDL_Rect m_buttonShape;
    
    bool m_hover;
        
        n8::Command* m_command;
};
    
}

#endif /* defined(BUTTON_H) */
