/*
 * Dialog.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            11/9/14
 * Organization:    n8Tech
 *
 */

#ifndef N8_GUI_DIALOG
#define N8_GUI_DIALOG

#include <stdio.h>

#include <SDL2/SDL.h>
#include "SDL2_image/SDL_image.h"
#include "SDL2_ttf/SDL_ttf.h"

#include "Window.h"
#include "Container.h"
#include "Button.h"
#include "Texture.h"

#include <string>

namespace gui {
    

class Dialog : public Container {
    friend class DialogBuilderInterface;
public:
    enum class EResultCode{POSITIVE, NEUTRAL, NEGATIVE};
    
    Dialog(std::shared_ptr<n8::Window>, int, int, int, int );
    ~Dialog();
    
    void SetIsOpen();
    void SetTitle(std::string);
    
    virtual void Dismiss();

    virtual bool CheckMouseClickDown(int, int) override;
    virtual bool CheckMouseClickUp(int, int) override;
    virtual bool CheckMouseMove(int,int) override;
    
    virtual void SetPositiveButton(std::string, std::function<void()>);
    virtual void SetPositiveButton(std::string, int, int, std::function<void()>);
    
    virtual void SetNegativeButton(std::string, std::function<void()>);
    virtual void SetNegativeButton(std::string, int, int, std::function<void()>);
    
    virtual void SetNeutralButton(std::string, std::function<void()>);
    virtual void SetNeutralButton(std::string, int, int, std::function<void()>);
    
    virtual void SetOnDismissListener(std::function<void(Dialog::EResultCode)>);
    
    virtual void SetOnPositiveClickedListener(std::function<void()>);
    virtual void SetOnNegativeClickedListener(std::function<void()>);
    virtual void SetOnNeutralClickedListener(std::function<void()>);
    
    virtual void Build() = 0;

    bool Update(Uint32 p_currentTime);
    void Draw(const std::shared_ptr<n8::Window>) const override;
    
protected:
    
    std::string mTitle;
    n8::Texture* mTitleTextTexture; /** < Texture used to display the text */
    
    bool mIsOpen;
    
    EResultCode mResult;
    
    std::shared_ptr<gui::Button> mPositiveButton;
    std::shared_ptr<gui::Button> mNegativeButton;
    std::shared_ptr<gui::Button> mNeutralButton;
    
    std::function<void(EResultCode)> mDismissedListener;
    std::function<void()> mPositiveListener;
    std::function<void()> mNegativeListener;
    std::function<void()> mNeutralListener;
    
private:
    
};
    
}

#endif /* defined(N8_GUI_DIALOG) */
