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
gui::GUI::GUI(n8::Window* p_window) :   m_style("Roboto.ttf"),
                    m_window(p_window),
                    m_hasFocus(false),
                    m_built(false)
{
    
}

/** Destructor */
gui::GUI::~GUI(){
    while (!mDialogStack.empty()) {
        mDialogStack.pop();
    }
    
    for (auto element : m_guiElements){
        if (element) {
            delete element;
            element = nullptr;
        }
    }
    
    m_window = nullptr;
}

/** Builds all elements in the GUI */
void gui::GUI::Build(){
    for (auto element : m_guiElements){
        element->Build(m_window);
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

void gui::GUI::ShowDialog(gui::Dialog * pDialog){
    pDialog->SetStyle(m_style);
    pDialog->Build(m_window);
    mDialogStack.push(pDialog);
}

void gui::GUI::RemoveElement(gui::GUIElement* p_widget){
    for (int i = 0; i < m_guiElements.size(); i++) {
        if (m_guiElements[i] == p_widget) {
            m_guiElements.erase(m_guiElements.begin() + i);
            break;
        }
    }
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
    if(!mDialogStack.empty()){
        bool clickedDown = mDialogStack.top()->CheckMouseClickDown(p_x, p_y);
        if (!clickedDown) {
            cout << "check click down was false" << endl;
            mDialogStack.top()->Dismiss();
            mDialogStack.pop();
        }else{
            cout << "check click down was true" << endl;
        }
        return clickedDown;
    }
    
    bool returnValue = false;
    for (int i = 0; i < m_guiElements.size(); i++) {
        if( m_guiElements[i]->CheckMouseClickDown(p_x,p_y) ){
            returnValue = true;
        }
    }
    
    return returnValue;
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
    if(!mDialogStack.empty()){
        return mDialogStack.top()->CheckMouseClickUp(p_x, p_y);
    }
    
    bool returnValue = false;
    for (int i = 0; i < m_guiElements.size(); i++) {
        if( m_guiElements[i]->CheckMouseClickUp(p_x,p_y) ){
            returnValue = true;
        }
    }
    
    return returnValue;
}

/** Handles the mouse move event for all elements in the gui
 *
 *  @return bool Returns True if any element was moved over
 */
bool gui::GUI::CheckMove(int p_x, int p_y){
    if(!mDialogStack.empty()){
        return mDialogStack.top()->CheckMouseMove(p_x, p_y);
    }
    
    bool returnValue = false;
    for (int i = 0; i < m_guiElements.size(); i++) {
        if( m_guiElements[i]->CheckMouseMove(p_x, p_y) ){
            returnValue = true;
        }
    }
    
    return returnValue;
}

/** Draws the gui to the given window
 *
 *  @param p_window The game's window that can be drawn to
 */
void gui::GUI::Draw(n8::Window* p_window){
    if(!mDialogStack.empty()){
        mDialogStack.top()->Draw(p_window);
    }
    
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
    if(!mDialogStack.empty()){
        return mDialogStack.top()->Update(p_currentTime);
    }
    
    for(auto element : m_guiElements){
        if(element->Update(p_currentTime)){
            m_hasFocus = true;
        }
    }
    //cout << "*** done ***" << endl;
    return m_hasFocus;
}

/** Returns whether the gui has the user focus
 *
 *  @return bool True if the gui has user focus
 */
bool gui::GUI::HasFocus(){
    return m_hasFocus;
}