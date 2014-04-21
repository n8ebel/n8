//
//  GUI.h
//  DevApp
//
//  Created by Nate Ebel on 4/21/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#ifndef __DevApp__GUI__
#define __DevApp__GUI__

#include <iostream>
#include <vector>

#include "Container.h"

namespace gui{
    class GUI : public Container{
    public:
        GUI();
        ~GUI();
        
        void CheckMouse();
        
    private:
        
        
    };
}

#endif /* defined(__DevApp__GUI__) */
