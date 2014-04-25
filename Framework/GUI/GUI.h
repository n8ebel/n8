//
//  GUI.h
//  DevApp
//
//  Created by Nate Ebel on 4/21/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#ifndef __DevApp__GUI__
#define __DevApp__GUI__

#include <iostream>
#include <vector>

#include "Window.h"
#include "Container.h"
#include "InputBox.h"

namespace gui{
    class GUI {
    public:
        GUI();
        ~GUI();
        
        void AddElement(GUIElement*);
        bool CheckClickDown(int p_x, int p_y);
        bool CheckClickUp(int p_x, int p_y);
        bool CheckMove();
        void Draw(n8::Window*);
        void ProcessInput(SDL_Event*);
        bool Update(Uint32 p_currentTime);
        
        bool HasFocus();
    private:
        std::vector<GUIElement*> m_guiElements;
        bool m_hasFocus;
    };
}

#endif /* defined(__DevApp__GUI__) */
