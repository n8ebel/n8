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
#include "Texture.h"
#include "Log.h"

namespace gui{

    /** \class Button
     *  \brief A gui element that can be clicked, and will perform some action.
     */
class Button : public GUIElement{
    public:
    
        Button(std::shared_ptr<n8::Window> p_window,
               std::string p_id,
               std::string p_text,
               int p_x, int p_y,
               int p_w, int p_h);
    
        Button(std::shared_ptr<n8::Window> p_window,
               std::string p_id,
               std::string p_text,
               int p_x, int p_y, int p_w, int p_h,
               std::function<void()> func);
    
        ~Button();
    
        void SetTextSize(int);
    
        void Draw(const std::shared_ptr<n8::Window>) const override;
        bool Update(Uint32 p_currentTime) override;
    
    private:
    
        std:: string m_text;  /** < The test displayed on the button */
        std::unique_ptr<n8::Texture> m_textTexture; /** < Texture used to display the text */
    
        void drawHovered(const std::shared_ptr<n8::Window>) const;
        void drawNeutral(const std::shared_ptr<n8::Window>) const;
        void drawFocused(const std::shared_ptr<n8::Window>) const;
        void drawPressed(const std::shared_ptr<n8::Window>) const;
        void drawPressedAndHovered(const std::shared_ptr<n8::Window>) const;
        void drawSelected(const std::shared_ptr<n8::Window>) const;
        void drawSelectedAndHovered(const std::shared_ptr<n8::Window>) const;
    
        void loadFontTexture(int);
};
    
}

#endif /* defined(BUTTON_H) */
