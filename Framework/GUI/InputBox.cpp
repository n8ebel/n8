/*
 * InputBox.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            4/24/14
 * Organization:    n8Tech
 *
 */

#include "InputBox.h"

/** Constructor
 *  Inititlizes parent class {@link GUIElement}
 *  Initializes flags, and strings
 *
 *  @param p_x The x position of the inputbox
 *  @param p_y The y position of the inputbox
 *  @param p_w The width of the inputbox
 *  @param p_h The height of the inputbox
 */
gui::InputBox::InputBox(int p_x, int p_y, int p_w, int p_h) : GUIElement(p_x,p_y,p_w,p_h){
    
    m_lastTime = 0;
    m_hintString = "";
    m_inputString = "";
    
    m_cursorShown = false;
    m_hasFocus = false;
    m_updateTexture = true;
}

/** Constructor
 *  Inititlizes parent class {@link GUIElement}
 *  Initializes flags, and strings
 *
 *  @param p_x The x position of the inputbox
 *  @param p_y The y position of the inputbox
 *  @param p_w The width of the inputbox
 *  @param p_h The height of the inputbox
 *  @param p_hint The hint string for the input box
 */
gui::InputBox::InputBox(int p_x, int p_y, int p_w, int p_h, std::string p_hint) : GUIElement(p_x,p_y,p_w,p_h)
{

    m_lastTime = 0;
    m_hintString = p_hint;
    m_inputString = "";
    
    m_cursorShown = false;
    m_hasFocus = false;
    m_updateTexture = true;
}

/** Destructor
 *  Frees texture
 */
gui::InputBox::~InputBox(){
    if (m_texture != nullptr) {
        SDL_DestroyTexture(m_texture);
        m_texture = nullptr;
    }
}

/** Builds the inputbox.
 *  Currently building does nothing but change the build flag
 */
void gui::InputBox::Build(){
    m_built = true;
}

/** Cheks mouse move event
 *  Currently, mouse move events don't affect the inputbox
 *
 *  @return False
 */
bool gui::InputBox::CheckMouseMove(int p_x, int p_y){
    return false;
}

/** Checks whether the inputbox was clicked down
 *  If the user clicked within the inputbox, the box gains the focus
 *   and input can then be entered into the inputbox.
 *  To allow input to be entered, SDL_StartTextInput() is called if the input
 *   box was clicked.
 *
 *
 *  @param p_x The x coordinate of the mouse click
 *  @param p_y The y coordinate of the mouse click
 *
 *  @return bool Returns true if the inputbox was clicked
 */
bool gui::InputBox::CheckMouseClickDown(int p_x, int p_y){
    if( p_x >= m_rectangle.GetX() && p_x <= m_rectangle.GetX() + m_rectangle.GetW() && p_y >= m_rectangle.GetY() && p_y <= m_rectangle.GetY() + m_rectangle.GetH()){
        SDL_StartTextInput();
        m_hasFocus = true;
        return true;
    }
    else{
        m_hasFocus = false;
        SDL_StopTextInput();
        return false;
    }
    m_updateTexture = true;
    return false;
}

/** Checks whether the inputbox was clicked up
 *  Currently mouse click up events don't affect inputbox
 *
 *  @param p_x The x coordinate of the mouse click
 *  @param p_y The y coordinate of the mouse click
 *
 *  @return bool False
 */
bool gui::InputBox::CheckMouseClickUp(int p_x, int p_y){
    
    return false;
}

/** Draws the inputbox based on its current state
 *
 *  @param p_window Pointer to the game window passed from
 *   {@link State#Render(n8::Window*) State.Render(n8::Window*)}
 */
void gui::InputBox::Draw(n8::Window* p_window){
    
    if(m_updateTexture){
        UpdateTexture(p_window);
    }
    
    SDL_Renderer* renderer= p_window->GetRenderer();
    
    //draw box background
    SDL_SetRenderDrawColor( renderer,   m_style->GetColor(Style::EStyleColor::InputBackground).GetR(),
                                        m_style->GetColor(Style::EStyleColor::InputBackground).GetG(),
                                        m_style->GetColor(Style::EStyleColor::InputBackground).GetB(),
                                        m_style->GetColor(Style::EStyleColor::InputBackground).GetA()
                           );
    
    SDL_RenderFillRect( renderer, m_rectangle.GetRect() );
    
    //draw outline if has focus
    if (m_hasFocus) {
        SDL_SetRenderDrawColor( renderer,    m_style->GetColor(Style::EStyleColor::Focus).GetR(),
                                            m_style->GetColor(Style::EStyleColor::Focus).GetG(),
                                            m_style->GetColor(Style::EStyleColor::Focus).GetB(),
                                            m_style->GetColor(Style::EStyleColor::Focus).GetA()
        );
        
        SDL_RenderDrawRect(renderer, m_rectangle.GetRect());
    }
    else{
        SDL_SetRenderDrawColor( renderer,    m_style->GetColor(Style::EStyleColor::Default).GetR(),
                               m_style->GetColor(Style::EStyleColor::Default).GetG(),
                               m_style->GetColor(Style::EStyleColor::Default).GetB(),
                               m_style->GetColor(Style::EStyleColor::Default).GetA()
                               );
        
        SDL_RenderDrawRect(renderer, m_rectangle.GetRect());
    }
    
    //draw text
    if (m_hintString != "" || m_inputString != "") {
        m_textTexture.render(p_window->GetRenderer(),   m_rectangle.GetX() + M_TEXT_OFFSET_X,
                             m_rectangle.GetY() + M_TEXT_OFFSET_Y);
    }
    
    //draw cursor
    if (m_cursorShown && m_hasFocus) {
        int x = m_rectangle.GetX() + M_CURSOR_OFFSET_X + m_textTexture.getWidth() + M_TEXT_OFFSET_X;
        int y1 = m_rectangle.GetY() + 10;
        int y2 = m_rectangle.GetY() + m_rectangle.GetH() - 10;
        SDL_SetRenderDrawColor(  renderer,    m_style->GetColor(Style::EStyleColor::Cursor).GetR(),
                               m_style->GetColor(Style::EStyleColor::Cursor).GetG(),
                               m_style->GetColor(Style::EStyleColor::Cursor).GetB(),
                               m_style->GetColor(Style::EStyleColor::Cursor).GetA()
                               );
        
        SDL_RenderDrawLine(renderer, x, y1, x, y2);
    }
    
}

/** Handles keyboard text input for user input
 *  When the inputbox has the focus, keyboard events
 *   are routed to this method so text input can be
 *   stored and drawn.
 *
 *  @param p_event A pointer to an SDL_Event object
 */
void gui::InputBox::HandleKeyboardInput(SDL_Event* p_event){
    
    if(m_hasFocus){
        SDL_Event e = *p_event;
        if( e.type == SDL_KEYDOWN )
        {
            //Handle backspace
            if( e.key.keysym.sym == SDLK_BACKSPACE && m_inputString.length() > 0 )
            {
                //lop off character
                m_inputString.pop_back();
                m_updateTexture = true;
            }
            //Handle copy
            else if( e.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL )
            {
                m_inputString = SDL_SetClipboardText( m_inputString.c_str() );
            }
            //Handle paste
            else if( e.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL )
            {
                m_inputString = SDL_GetClipboardText();
                m_updateTexture = true;
            }
        }
        //Special text input event
        else if( e.type == SDL_TEXTINPUT )
        {
            //Not copy or pasting
            if( !( ( e.text.text[ 0 ] == 'c' || e.text.text[ 0 ] == 'C' ) && ( e.text.text[ 0 ] == 'v' || e.text.text[ 0 ] == 'V' ) && SDL_GetModState() & KMOD_CTRL ) )
            {
                //Append character
                m_inputString += e.text.text;
                m_updateTexture = true;
            }
        }
    }
}

/** Updates inputbox every frame.
 *  Updates whether cursor is on or off
 *
 *  @return m_hasFocus
 */
bool gui::InputBox::Update(Uint32 p_currentTime){
    if ( (p_currentTime - m_lastTime) > 500) {
        m_cursorShown = !m_cursorShown;
        m_lastTime = p_currentTime;
    }
    
    return m_hasFocus;
}

/** Gets the text currently in the inputbox
 *
 *  @return m_inputString The string entered into the inputbox
 */
std::string gui::InputBox::GetText(){
    return m_inputString;
}

/** Updates the text texture based on the current
 *   input within the inputbox
 */
void gui::InputBox::UpdateTexture(n8::Window* p_window){
    
    //Text is not empty
    if( m_inputString.length() > 0)
    {
        
        //load input text to texture
        m_textTexture.loadFromRenderedText( m_style->GetWindow()->GetRenderer(), m_style->GetFont()->GetFont(), m_inputString.c_str(), (m_style->GetColor(Style::EStyleColor::Font).GetColor()) );
       
    }
    //Text is empty
    else
    {
        if (m_hintString != "" && !m_hasFocus) {
            //load hint text to texture
            m_textTexture.loadFromRenderedText(m_style->GetWindow()->GetRenderer(),m_style->GetFont()->GetFont(),  m_hintString, (m_style->GetColor(Style::EStyleColor::Hint).GetColor()) );
        }
        else{
            //load empty texture
            m_textTexture.loadFromRenderedText(m_style->GetWindow()->GetRenderer(),  m_style->GetFont()->GetFont()," ", (m_style->GetColor(Style::EStyleColor::Font).GetColor()) );
        }
      
    }
                                                         
    
}