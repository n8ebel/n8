/*
 * GUIElement.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            4/20/14
 * Organization:    n8Tech
 *
 */

#ifndef GUI_ELEMENT_H
#define GUI_ELEMENT_H

#include <iostream>

#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "SDL2_ttf/SDL_ttf.h"

#include "Window.h"
#include "Rectangle.h"
#include "LTexture.h"
#include "Font.h"
#include "Color.h"
#include "Style.h"

#include "Command.h"

namespace gui {
    
/** \class GUIElement
 *  \brief Abstract base class for gui elements suchas as buttons or menus
 *
 *  GUIElement provides an abstract base class for all gui elements including, buttons, toolbars, labels, etc.
 */
class GUIElement{

public:
    enum class State{Neutral, Focused, Hovered, Pressed, Selected };
    
    GUIElement();
    GUIElement(int p_x, int p_y, int p_w, int p_h);
    virtual ~GUIElement();
    
//Implemented methods
    virtual void ChangePosition(int p_x, int p_y);
    virtual void OffsetPosition(int p_xOffset, int p_yOffset);
    virtual void SetStyle(Style p_style);
    //Style GetStyle() const;
    
    void SetColor(Style::EStyleColor p_color, int p_r, int p_g, int p_b);
    void SetColor(Style::EStyleColor p_color, int p_r, int p_g, int p_b, int p_a);
    
//Pure virtual methods
    virtual void Build(n8::Window*);  /** < Performs any state-based initialization that can't be done at object construction.  Called from GUI object or on individual element basis. **/
    
    virtual void Draw(n8::Window*) = 0;  /** < Renders the element to the screen. **/
    
    virtual bool CheckMouseClickDown(int p_x, int p_y);  /** Checks if a mouse click down action took place within the element and responds appropriately.  **/
    virtual bool CheckMouseClickUp(int p_x, int p_y);  /** Checks if a mouse click up action took place within the element and responds appropriately.  **/
    
    virtual bool CheckMouseMove(int p_x, int p_y);  /** Responds to a mouse move action.  **/

    virtual bool Update(Uint32 p_currentTime) = 0;  /** Handles any updating of the element that needs to happen during every frame.  **/
    
    void setClickHandler(std::function<void()> function);
    

protected:
    Style m_style; /** < Pointer to a Style object that determeins the color style of the element **/
    n8::Rectangle m_rectangle; /** < Stores the positions and size of the element **/
    SDL_Texture* m_texture; /** < Pointer to texture used render the element **/

    bool m_built;  /** < Flag to determine if the element was successfully built.  Some elements must be built using current state information before the can be rendered.  This flag allows elements that weren't built to not perform destructive operations. **/
    
    State m_state;
    
//    bool m_hasFocus; /** < Flag to determine if an element has the current focus of the gui.  For example, if an input box has been clicked it will receive the focust **/
//    
//    bool m_hover; /** < mouse is hovering over the button **/
//    bool m_pressed; /** < whether button appears pressed down **/
    bool m_mouseClickedDown; /** < whether button is currently pressed down **/
    unsigned m_timeClickedDown; /** < how long the button has appeared pressed down **/
    
    std::function<void()> m_function;  /** < Lambda function to be called when button is clicked down */
    
    int m_x;
    int m_y;
    int m_w;
    int m_h;
    
    bool positionWithinElement(int x, int y);
    
};
    
}

#endif /* defined(GUI_ELEMENT_H) */
