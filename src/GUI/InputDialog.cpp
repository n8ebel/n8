//
//  InputDialog.cpp
//  n8_Game
//
//  Created by Nate Ebel on 11/8/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#include "../Headers/InputDialog.h"

namespace gui {
    
    const Uint16 InputDialog::INPUTBOX_HORIZONTAL_MARGIN = 50;
    
    const Uint16 InputDialog::INPUTBOX_VERTICAL_MARGIN = 100;
    
    const Uint16 InputDialog::INPUTBOX_HEIGHT = 40;
    
    InputDialog::Builder::Builder(std::shared_ptr<n8::Window> pWindow) : DialogBuilderInterface(pWindow) {
        int x = pWindow->GetWidth()/2 - Style::DEFAULT_DIALOG_WIDTH/2;
        int y = pWindow->GetHeight()/2 - Style::DEFAULT_DIALOG_HEIGHT/2;
        mDialog = std::make_shared<InputDialog>(pWindow, "", x, y, Style::DEFAULT_DIALOG_WIDTH, Style::DEFAULT_DIALOG_HEIGHT);
        DialogBuilderInterface::mDialog = mDialog;
    }
    
    InputDialog::Builder::~Builder(){
        mDialog = nullptr;
    }
    
    void InputDialog::Builder::SetHintText(std::string pHintText){
        mHintText = pHintText;
        mDialog->SetHintText(pHintText);
    }
    
    void gui::InputDialog::SetHintText(std::string hintText){
        mInputBox->SetHintText(hintText);
    }
    std::string gui::InputDialog::GetInput() const{
        if (mInputBox) {
            return mInputBox->GetText();
        }
        
        return "Error: InputDialog.mInputBox was null";
    }
    
    void InputDialog::HandleKeyboardInput(SDL_Event* event) const{
        if (mInputBox) {
            mInputBox->HandleKeyboardInput(event);
        }
    }

    InputDialog::InputDialog(std::shared_ptr<n8::Window> p_window, std::string id, int p_x, int p_y, int p_w, int p_h) : AlertDialog(p_window, p_x, p_y, p_w, p_h){
        mInputBox = std::make_shared<InputBox>(p_window, id, INPUTBOX_HORIZONTAL_MARGIN, INPUTBOX_VERTICAL_MARGIN, m_w - 2 * INPUTBOX_HORIZONTAL_MARGIN, INPUTBOX_HEIGHT);
        AddElement(mInputBox);
    }
    
    InputDialog::~InputDialog(){
        AlertDialog::~AlertDialog();
    }

}