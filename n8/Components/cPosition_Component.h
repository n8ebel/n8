//
//  cPosition_Component.h
//  SDL_Test
//
//  Created by Nate Ebel on 7/22/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef SDL_Test_cPosition_Component_h
#define SDL_Test_cPosition_Component_h

#include "cPoint.h"

using namespace std;

class cPosition_Component : public cComponent {
private:
    cPoint* position;
    
public:
    ~cPosition_Component();
    cPosition_Component(string newID, cPoint* newPosition);
    cPosition_Component(string newID, int initX, int initY);
    cPoint* get_position();
};

#endif
