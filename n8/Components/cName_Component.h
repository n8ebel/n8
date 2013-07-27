//
//  cName_Component.h
//  SDL_Test
//
//  Created by Nate Ebel on 7/21/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef SDL_Test_cName_Component_h
#define SDL_Test_cName_Component_h

#include <string>
#include "cComponent.h"

using namespace std;

class cName_Component : public cComponent {
private:
    string name;
    
public:
    ~cName_Component();
    cName_Component();
    cName_Component(string newID,string newName);
    string get_name();
};

#endif
