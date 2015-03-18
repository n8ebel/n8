/*
 * AlertDialog.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            10/24/14
 * Organization:    n8Tech
 *
 */

#ifndef N8_GUI_ALERTDIALOG_H
#define N8_GUI_ALERTDIALOG_H

#include "/Library/Frameworks/SDL2.framework/Versions/A/Headers/SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include "Window.h"
#include "Container.h"
#include "Button.h"
#include "Dialog.h"
#include "DialogBuilderInterface.h"
#include "Texture.h"

#include <string>


namespace gui{
    
    class AlertDialog : public Dialog {
        friend class DialogBuilderInterface;
    public:
        
        class Builder : public DialogBuilderInterface{
            
            public:
            Builder(std::shared_ptr<n8::Window>);
            ~Builder();
            
            Builder* SetOnDismissedListener(std::function<void(Dialog::EResultCode)>);
        };
    
     
        AlertDialog(std::shared_ptr<n8::Window> p_window, int p_x, int p_y, int p_w, int p_h);
        ~AlertDialog();
        void Build();
        
    };
}


#endif /* defined(N8_GUI_ALERTDIALOG_H) */
