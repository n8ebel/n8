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
        Container(int p_x, int p_y, int p_w, int p_h);
        virtual ~Container();
        
        virtual void Draw(n8::Window*) override;
        virtual bool CheckMouseClickDown(int p_x, int p_y) override;
        virtual bool CheckMouseClickUp(int p_x, int p_y) override;
        virtual bool CheckMouseMove() override;
        
        void AddElement(GUIElement*);
        
    protected:
        std::vector<GUIElement*> m_elements;
        
    };
}

#endif /* defined(__DevApp__Container__) */
