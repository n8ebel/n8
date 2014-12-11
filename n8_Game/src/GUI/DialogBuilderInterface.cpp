//
//  DialogBuilderInterface.cpp
//  n8_Game
//
//  Created by Nate Ebel on 11/8/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#include <stdio.h>

#include "Window.h"
#include "Dialog.h"
#include "DialogBuilderInterface.h"

namespace gui {

    DialogBuilderInterface::DialogBuilderInterface(std::shared_ptr<n8::Window> pWindow){ }

    std::shared_ptr<Dialog> DialogBuilderInterface::Create(){
        mDialog->Build();
        return mDialog;
    }

    DialogBuilderInterface* DialogBuilderInterface::SetWidth(int width){
        mDialog->SetWidth(width);
        return this;
    }

    DialogBuilderInterface* DialogBuilderInterface::SetHeight(int height){
        mDialog->SetHeight(height);
        return this;
    }

    DialogBuilderInterface* DialogBuilderInterface::SetTitle(std::string pString){
        mDialog->SetTitle(pString);
        return this;
    }

    DialogBuilderInterface* DialogBuilderInterface::SetPositiveButton(std::string text, std::function<void()> function){
        return SetPositiveButton(text, Style::DEFAULT_BUTTON_WIDTH, Style::DEFAULT_BUTTON_HEIGHT, function);
    }

    DialogBuilderInterface* DialogBuilderInterface::SetPositiveButton(std::string text, int width, int height, std::function<void()> function){
        mDialog->SetPositiveButton(text, width, height, function);
        return this;
    }

    DialogBuilderInterface* DialogBuilderInterface::SetNegativeButton(std::string text, std::function<void()> function){
        return SetNegativeButton(text, Style::DEFAULT_BUTTON_WIDTH, Style::DEFAULT_BUTTON_HEIGHT, function);
    }

    DialogBuilderInterface* DialogBuilderInterface::SetNegativeButton(std::string text, int width, int height, std::function<void()> function){
        mDialog->SetNegativeButton(text, width, height, function);
        return this;
    }

    DialogBuilderInterface* DialogBuilderInterface::SetNeutralButton(std::string text, std::function<void()> function){
        return SetNeutralButton(text, Style::DEFAULT_BUTTON_WIDTH, Style::DEFAULT_BUTTON_HEIGHT, function);
    }

    DialogBuilderInterface* DialogBuilderInterface::SetNeutralButton(std::string text, int width, int height, std::function<void()> function){
        mDialog->SetNeutralButton(text, width, height, function);
        return this;
    }
    
    DialogBuilderInterface* DialogBuilderInterface::SetOnDismissListener(std::function<void(Dialog::EResultCode code)> function){
        mDialog->SetOnDismissListener(function);
        return this;
    }

}