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
#include <sstream>

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
        Button(std::string p_id,
               std::string p_text,
                int p_x, int p_y, int p_w, int p_h,
                n8::Command* p_command);
    
        Button(std::string p_id,
               std::string p_text,
               int p_x, int p_y, int p_w, int p_h,
               std::function<void()> func);
    
        ~Button();
    
        virtual void Build() override;
        void Draw(n8::Window*) override;
        virtual bool CheckMouseClickDown(int p_x, int p_y) override;
        virtual bool CheckMouseClickUp(int p_x, int p_y) override;
        virtual bool CheckMouseMove() override;
        bool Update(Uint32 p_currentTime) override;
    
    private:
        std::string m_id;
    
        bool m_hover; /** < mouse is hovering over the button **/
        bool m_pressed; /** < whether button appears pressed down **/
        bool m_mouseClickedDown; /** < whether button is currently pressed down **/
        unsigned m_timeClickedDown; /** < how long the button has appeared pressed down **/
    
        std:: string m_text;
        LTexture m_textTexture;
        n8::Command* m_command;
        std::function<void()> m_function;
};
    
}

#endif /* defined(BUTTON_H) */
