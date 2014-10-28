/*
 * Dialog.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            10/24/14
 * Organization:    n8Tech
 *
 */

#ifndef N8_GUI_DIALOG_H
#define N8_GUI_DIALOG_H

#include <SDL2/SDL.h>
#include "SDL2_image/SDL_image.h"
#include "SDL2_ttf/SDL_ttf.h"

#include "Window.h"
#include "Container.h"
#include "Button.h"

#include <string>


namespace gui{
    class Dialog : public Container {
    public:
        static int DEFAULT_WIDTH;
        
        static int DEFAULT_HEIGHT;
        
        static int DEFAULT_TITLE_HEIGHT;

        class Builder{
            public:
            Builder(n8::Window*);
            
            Dialog* Create();
            
            Builder* SetTitle(std::string);
            Builder* SetPositiveButton(std::string, std::function<void()>);
            Builder* SetNegativeButton(std::string, std::function<void()>);
            Builder* SetNeutralButton(std::string, std::function<void()>);
            
            private:
            Dialog* mDialog;
        };
        
        ~Dialog();
        
        void Build(n8::Window*) override;
        
        bool CheckMouseClickDown(int, int) override;
        bool CheckMouseClickUp(int, int) override;
        bool CheckMouseMove(int,int) override;
        
        bool Update(Uint32 p_currentTime);
        
        void Draw(n8::Window*) override;
        
        void SetOnDismissedListener(std::function<void()>);
        void Dismiss();
        
    private:
        std::string mTitle;
        LTexture mTitleTextTexture; /** < Texture used to display the text */
        
        gui::Button* mPositiveButton;
        gui::Button* mNegativeButton;
        gui::Button* mNeutralButton;
        
        std::function<void()> mDismissedListener;
        std::function<void()> mPositiveListener;
        std::function<void()> mNegativeListener;
        std::function<void()> mNeutralListener;
        
        Dialog(int p_x, int p_y, int p_w, int p_h);
    };
}


#endif /* defined(N8_GUI_DIALOG_H) */
