//
//  Container.h
//  DevApp
//
//  Created by Nate Ebel on 4/21/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#ifndef __DevApp__Container__
#define __DevApp__Container__

#include <iostream>
#include <vector>

#include "GUIElement.h"
#include "Widget.h"



namespace gui{
    class Container : public GUIElement{
    public:
        Container();
        virtual ~Container() = 0;
        
        virtual void Draw(n8::Window*) = 0;
        virtual void CheckMouse() = 0;
        
    protected:
        std::vector<Widget*> m_widgets;
        
    };
}

#endif /* defined(__DevApp__Container__) */
