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
#include "GUIElement.h"
#include "Command.h"
#include "Log.h"

namespace gui{

    class Button : public GUIElement{
public:
        Button(std::string p_id, int p_x, int p_y, int p_w, int p_h, n8::Command* p_command);
    ~Button();
    
    void Draw(n8::Window*) override;
    virtual bool CheckMouseClickDown(int p_x, int p_y) override;
        virtual bool CheckMouseClickUp(int p_x, int p_y) override;
    virtual bool CheckMouseMove() override;
    
private:
    std::string m_id;
    
    bool m_hover;
        bool m_pressed;
        
    n8::Command* m_command;
};
    
}

#endif /* defined(BUTTON_H) */
