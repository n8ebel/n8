//
//  GUIElement.h
//  DevApp
//
//  Created by Nate Ebel on 4/21/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#ifndef __DevApp__GUIElement__
#define __DevApp__GUIElement__

#include <iostream>

#include "Window.h"

namespace gui {
    class GUIElement{
    public:
        GUIElement();
        virtual ~GUIElement();
        
        virtual void Draw(n8::Window*) = 0;
        virtual bool CheckMouse() = 0;
    private:
        
    };
}

#endif /* defined(__DevApp__GUIElement__) */
