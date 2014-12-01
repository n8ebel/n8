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
#include <stack>

#include "Window.h"
#include "Container.h"
#include "InputBox.h"
#include "Style.h"
#include "Button.h"
#include "GUIElement.h"
#include "Label.h"
#include "Dialog.h"
#include "InputDialog.h"
#include "ImageView.h"

namespace gui{
    
    /** \class GUI
     *  \brief Object used to define user interface
     *
     *  GUI allows gui elements to be added and interacted with.  Also maintains
     *  a style object to define how objects should look.
     */
    class GUI {
    public:
        GUI(std::shared_ptr<n8::Window> p_window);
        ~GUI();
        
        void AddElement(std::shared_ptr<GUIElement>);
        void RemoveElement(std::shared_ptr<GUIElement>);
        
        void ShowDialog(std::shared_ptr<Dialog>);
        
        bool CheckClickDown(int p_x, int p_y);
        bool CheckClickUp(int p_x, int p_y) const;
        bool CheckMove(int p_x, int p_y) const;
        bool HasFocus() const;
        
        
        void Draw() const;
        void ProcessInput(SDL_Event*) const;
        bool Update(Uint32 p_currentTime);
    private:
        std::shared_ptr<n8::Window> m_window;
        
        std::vector<std::shared_ptr<GUIElement>> m_guiElements; /** < List of gui elements that have been added and can be interacted with.  */
        std::stack<std::shared_ptr<Dialog>> mDialogStack;
        
        bool m_built;  /** < Flag to determine if the gui has been built by the user. */
        bool m_hasFocus; /** < Flag to indicate if the gui has the user focus. */
    };
}

#endif /* defined(GUI_H) */
