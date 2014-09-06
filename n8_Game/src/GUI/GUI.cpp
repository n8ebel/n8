/*
 * GUI.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            4/20/14
 * Organization:    n8Tech
 *
 */

#include "GUI.h"

/** Constructor */
gui::GUI::GUI(n8::Window* p_window, n8::Font* p_font) :   m_style(p_window,p_font),
                    m_hasFocus(false),
                    m_built(false)
{
    
}

/** Destructor */
gui::GUI::~GUI(){
    for (auto element : m_guiElements){
        if (element) {
            delete element;
            element = nullptr;
        }
    }
}

/** Builds all elements in the GUI */
void gui::GUI::Build(){
    for (auto element : m_guiElements){
        element->Build();
    }
    m_built = true;
}

/** Adds a new element to the gui.
 *
 *  @param p_newWidget The new element to add to the gui
 */
void gui::GUI::AddElement(gui::GUIElement* p_newWidget){
    p_newWidget->SetStyle(m_style);
    
    m_guiElements.push_back(p_newWidget);
}

void gui::GUI::RemoveElement(gui::GUIElement* p_widget){
    
}

/** Passes a mouse button down event to all added gui elements.
 *  These elements then can handle the event.
 *
 *  @param p_x The x coordinate of the mouse click
 *  @param p_y The y coordinate of the mouse click
 *
 *  @return bool Returns true if any element was clicked
 */
bool gui::GUI::CheckClickDown(int p_x, int p_y){
    for (int i = 0; i < m_guiElements.size(); i++) {
        if( m_guiElements[i]->CheckMouseClickDown(p_x,p_y) ){
            return true;
        }
    }
    
    return false;
}

/** Passes a mouse button up event to all added gui elements.
 *  These elements then can handle the event.
 *
 *  @param p_x The x coordinate of the mouse click
 *  @param p_y The y coordinate of the mouse click
 *
 *  @return bool Returns true if any element was clicked up
 */
bool gui::GUI::CheckClickUp(int p_x, int p_y){
    for (int i = 0; i < m_guiElements.size(); i++) {
        if( m_guiElements[i]->CheckMouseClickUp(p_x,p_y) ){
            return true;
        }
    }
    
    return false;
}

/** Handles the mouse move event for all elements in the gui
 *
 *  @return bool Returns True if any element was moved over
 */
bool gui::GUI::CheckMove(int p_x, int p_y){
    for (int i = 0; i < m_guiElements.size(); i++) {
        if( m_guiElements[i]->CheckMouseMove(p_x, p_y) ){
            return true;
        }
    }
    
    return false;
}

/** Draws the gui to the given window
 *
 *  @param p_window The game's window that can be drawn to
 */
void gui::GUI::Draw(n8::Window* p_window){
    for (int i = 0; i < m_guiElements.size(); i++) {
        m_guiElements[i]->Draw(p_window);
    }
}

/** Processes events to updated input box on key presses
 *
 *  @param e The event to check
 */
void gui::GUI::ProcessInput(SDL_Event* e){
    for(GUIElement* element : m_guiElements){
        if (dynamic_cast<InputBox*>(element) != nullptr) {
            dynamic_cast<InputBox*>(element)->HandleKeyboardInput(e);
        }
    }
}

/** Updates the gui and all added elements.
 *  Update methods on all elements allow states to be modified and events to be handled.
 *
 *  @param p_currentTime The current game time
 *
 *  @return bool True if any elements have focus
 */
bool gui::GUI::Update(Uint32 p_currentTime){
    m_hasFocus = false;
    for(auto element : m_guiElements){
        if(element->Update(p_currentTime)){
            m_hasFocus = true;
        }
    }
    
    return m_hasFocus;
}

/** Returns whether the gui has the user focus
 *
 *  @return bool True if the gui has user focus
 */
bool gui::GUI::HasFocus(){
    return m_hasFocus;
}