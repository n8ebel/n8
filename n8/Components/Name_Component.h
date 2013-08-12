/*
 * Name_Component.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

#ifndef SDL_Test_Name_Component_h
#define SDL_Test_Name_Component_h

#include <string>
#include "Component.h"

using namespace std;

class Name_Component : public Component {
private:
    string name_;   /** < A name for an entity **/
    
public:
    
    ~Name_Component();
    Name_Component(string newID,string newName);
    
    /** Used to get the name stored by the component
     *
     *  @return The name stored by the component 
     */
    string get_name() { return name_; }
};

#endif
