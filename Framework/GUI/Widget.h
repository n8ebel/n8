//
//  Widget.h
//  DevApp
//
//  Created by Nate Ebel on 4/21/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#ifndef __DevApp__Widget__
#define __DevApp__Widget__

#include <iostream>

#include "GUIElement.h"

namespace gui {
    class Widget : public GUIElement{
    public:
        Widget();
        virtual ~Widget();
        
        virtual void Draw(n8::Window*) = 0;
        virtual void CheckMouse() = 0;
        
    private:
    };
}

#endif /* defined(__DevApp__Widget__) */
