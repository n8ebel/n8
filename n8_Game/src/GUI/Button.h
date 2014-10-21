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
#include "Log.h"

namespace gui{

    /** \class Button
     *  \brief A gui element that can be clicked, and will perform some action.
     */
class Button : public GUIElement{
    public:
    
        Button(std::string p_id,
           std::string p_text,
           int p_x, int p_y, int p_w, int p_h);
    
        Button(std::string p_id,
               std::string p_text,
               int p_x, int p_y, int p_w, int p_h,
               std::function<void()> func);
    
        ~Button();
    
        virtual void Build(n8::Window*) override;
        void Draw(n8::Window*) override;
        bool Update(Uint32 p_currentTime) override;
    
    private:
        std::string m_id;
    
        std:: string m_text;  /** < The test displayed on the button */
        LTexture m_textTexture; /** < Texture used to display the text */
};
    
}

#endif /* defined(BUTTON_H) */
