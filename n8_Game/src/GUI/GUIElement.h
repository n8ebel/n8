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
    enum class State{Neutral, Focused, Hovered, Pressed, PressedAndHovered, Selected, SelectedAndHovered };
    
    GUIElement(std::shared_ptr<n8::Window> p_window, std::string p_id, int p_x, int p_y, int p_w, int p_h);
    virtual ~GUIElement();
    
//Implemented methods
    virtual void SetPosition(int p_x, int p_y);
    virtual void OffsetPosition(int p_xOffset, int p_yOffset);
    virtual void SetSize(int width, int height);
    virtual void SetWidth(int width);
    virtual void SetHeight(int height);
    int GetWidth() const;
    int GetHeight() const;
    int GetX() const;
    int GetY() const;
    
    Style GetStyle(){return m_style;}
    void SetStyle(Style p_style);
    
    void SetState(State newState);
    State GetState();
    
    void SetColor(Style::EStyleColor p_color, int p_r, int p_g, int p_b);
    void SetColor(Style::EStyleColor p_color, int p_r, int p_g, int p_b, int p_a);
    
    virtual void Draw(const std::shared_ptr<n8::Window>) const = 0;  /** < Renders the element to the screen. **/
    
    virtual bool CheckMouseClickDown(int p_x, int p_y);  /** Checks if a mouse click down action took place within the element and responds appropriately.  **/
    virtual bool CheckMouseClickUp(int p_x, int p_y);  /** Checks if a mouse click up action took place within the element and responds appropriately.  **/
    
    virtual bool CheckMouseMove(int p_x, int p_y);  /** Responds to a mouse move action.  **/

    virtual bool Update(Uint32 p_currentTime) = 0;  /** Handles any updating of the element that needs to happen during every frame.  **/
    
    void setClickHandler(std::function<void()> function);
 
protected:
    std::shared_ptr<n8::Window> m_window;
    Style m_style; /** < Pointer to a Style object that determeins the color style of the element **/
    n8::Rectangle m_rectangle; /** < Stores the positions and size of the element **/
    SDL_Texture* m_texture; /** < Pointer to texture used render the element **/

    bool m_built;  /** < Flag to determine if the element was successfully built.  Some elements must be built using current state information before the can be rendered.  This flag allows elements that weren't built to not perform destructive operations. **/
    
    State m_state;
    
    bool m_mouseClickedDown; /** < whether button is currently pressed down **/
    unsigned m_timeClickedDown; /** < how long the button has appeared pressed down **/
    
    std::function<void()> m_function;  /** < Lambda function to be called when button is clicked down */
    
    std::string m_id;
    
    int m_x;
    int m_y;
    int m_w;
    int m_h;
    
    bool positionWithinElement(int x, int y) const;
    
};
    
}

#endif /* defined(GUI_ELEMENT_H) */
