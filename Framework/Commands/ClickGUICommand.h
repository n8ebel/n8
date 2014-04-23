/*
 *  ClickGUICommand.h
 *  n8
 *
 *  Created by Nate Ebel on 4/23/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#ifndef CLICK_CUI_COMMAND_H
#define CLICK_CUI_COMMAND_H

#include <iostream>
#include <vector>

#include "PositionCommand.h"
#include "GUI.h"

namespace n8{
    
    class ClickGUICommand : public PositionCommand {
        
    public:
        ClickGUICommand(gui::GUI* p_gui);
        ~ClickGUICommand();
        virtual bool execute();
        bool execute(int p_x, int p_y);
        
    private:
        gui::GUI* m_gui;
        
    };
    
}



#endif /* defined(CLICK_CUI_COMMAND_H) */