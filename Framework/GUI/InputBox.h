/*
 * InputBox.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            4/24/14
 * Organization:    n8Tech
 *
 */

#ifndef INPUT_BOX_H
#define INPUT_BOX_H

#include <iostream>
#include <string>

#include "GUIElement.h"
#include "LTexture.h"

namespace gui {
    class InputBox : public GUIElement{
    public:
        InputBox(int p_x, int p_y, int p_w, int p_h);
        InputBox(int p_x, int p_y, int p_w, int p_h, std::string p_hint);
        ~InputBox();
        
        void Build();
        void Draw(n8::Window*) override;
        
        virtual bool CheckMouseClickDown(int p_x, int p_y) override;
        virtual bool CheckMouseClickUp(int p_x, int p_y) override;
        virtual bool CheckMouseMove() override;
        virtual void HandleKeyboardInput(SDL_Event*);
        virtual bool Update(Uint32 p_currentTime) override;
        
        std::string GetText();
    
    private:
        const unsigned M_TEXT_OFFSET_X = 10;
        const unsigned M_TEXT_OFFSET_Y = 10;
        const unsigned M_CURSOR_OFFSET_X = 2;
        
        LTexture m_textTexture;
        
        
        std::string m_hintString;
        std::string m_inputString;
        bool m_updateTexture;
        bool m_cursorShown;
        
        unsigned m_currentTime;
        unsigned m_lastTime;
        
        void UpdateTexture(n8::Window*);
    };
}

#endif /* defined(INPUT_BOX_H) */
