//
//  DialogBuilderInterface.h
//  n8_Game
//
//  Created by Nate Ebel on 11/8/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#ifndef N8_GUI_DIALOG_BUILDER_INTERFACE
#define N8_GUI_DIALOG_BUILDER_INTERFACE

#include "Dialog.h"

namespace gui {

class DialogBuilderInterface{
    
public:
    
    DialogBuilderInterface(std::shared_ptr<n8::Window>);
    
    virtual std::shared_ptr<Dialog> Create();
    
    virtual DialogBuilderInterface* SetHeight(int height);
    virtual DialogBuilderInterface* SetWidth(int width);
    
    virtual DialogBuilderInterface* SetTitle(std::string);
    
    virtual DialogBuilderInterface* SetPositiveButton(std::string, std::function<void()>);
    virtual DialogBuilderInterface* SetPositiveButton(std::string, int, int, std::function<void()>);
    
    virtual DialogBuilderInterface* SetNegativeButton(std::string, std::function<void()>);
    virtual DialogBuilderInterface* SetNegativeButton(std::string, int, int, std::function<void()>);
    
    virtual DialogBuilderInterface* SetNeutralButton(std::string, std::function<void()>);
    virtual DialogBuilderInterface* SetNeutralButton(std::string, int, int, std::function<void()>);
    
    virtual DialogBuilderInterface* SetOnDismissListener(std::function<void(Dialog::EResultCode)>);
    
protected:
    std::shared_ptr<Dialog> mDialog;
    
private:
    
};
    
}

#endif //(N8_GUI_DIALOG_BUILDER_INTERFACE)
