/*
 * InputDialog.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            11/8/14
 * Organization:    n8Tech
 *
 */

#ifndef N8_GUI_INPUT_DIALOG
#define N8_GUI_INPUT_DIALOG

#include <stdio.h>

#include "AlertDialog.h"
#include "InputBox.h"

namespace gui {

class InputDialog : public AlertDialog{
    friend class DialogBuilderInterface;
public:
    
    class Builder : public DialogBuilderInterface{
        
    public:
        Builder(std::shared_ptr<n8::Window>);
        ~Builder();
        
        void SetHintText(std::string);
        
    private:
        std::string mHintText;
        std::shared_ptr<InputDialog> mDialog;
    };
    
    void SetHintText(std::string);
    std::string GetInput();
    void HandleKeyboardInput(SDL_Event*);
    
    InputDialog(std::shared_ptr<n8::Window> p_window, std::string, int p_x, int p_y, int p_w, int p_h);
    ~InputDialog();
    
private:
    static const Uint16 INPUTBOX_HORIZONTAL_MARGIN;
    
    static const Uint16 INPUTBOX_VERTICAL_MARGIN;
    
    static const Uint16 INPUTBOX_HEIGHT;
    
    
    
    std::shared_ptr<InputBox> mInputBox;
    
};
    
}

#endif /* defined(N8_GUI_INPUT_DIALOG) */
