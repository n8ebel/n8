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
#include "Style.h"

namespace gui{
    class GUI {
    public:
        GUI(n8::Window* p_window, n8::Font* p_font);
        ~GUI();
        
        void AddElement(GUIElement*);
        
        bool CheckClickDown(int p_x, int p_y);
        bool CheckClickUp(int p_x, int p_y);
        bool CheckMove();
        bool HasFocus();
        
        Style GetStyle(){return m_style;}
        
        void Build();
        void Draw(n8::Window*);
        void ProcessInput(SDL_Event*);
        bool Update(Uint32 p_currentTime);
    private:
        Style m_style;
        std::vector<GUIElement*> m_guiElements;
        
        bool m_built;
        bool m_hasFocus;
    };
}

#endif /* defined(GUI_H) */
