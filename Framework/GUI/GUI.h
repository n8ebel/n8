/*
 * GUI.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            4/20/14
 * Organization:    n8Tech
 *
 */

#ifndef GUI_H
#define GUI_H

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

#endif /* defined(GUI_H) */
