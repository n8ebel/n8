//
//  InputBox.h
//  DevApp
//
//  Created by Nate Ebel on 4/24/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#ifndef __DevApp__InputBox__
#define __DevApp__InputBox__

#include <iostream>
#include <string>

#include "GUIElement.h"
#include "LTexture.h"

namespace gui {
    class InputBox : public GUIElement{
    public:
        InputBox(int p_x, int p_y, int p_w, int p_h);
        ~InputBox();
        
        void Draw(n8::Window*) override;
        
        virtual bool CheckMouseClickDown(int p_x, int p_y) override;
        virtual bool CheckMouseClickUp(int p_x, int p_y) override;
        virtual bool CheckMouseMove() override;
        virtual void HandleKeyboardInput(SDL_Event*);
        virtual bool Update(Uint32 p_currentTime) override;
    
    private:
        //Set text color as black
        SDL_Color m_textColor;
        LTexture texture;
        TTF_Font* m_font;
        
        std::string m_inputString;
        bool m_updateTexture;
        bool m_cursorShown;
        
        unsigned m_currentTime;
        unsigned m_lastTime;
        
        unsigned m_textOffsetY;
        unsigned m_textOffsetX;
    };
}

#endif /* defined(__DevApp__InputBox__) */
