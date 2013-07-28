/*
 * cName_Component.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

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
