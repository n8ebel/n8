/*
 * cControllable_Coponent.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            8/6/13
 * Organization:    n8Tech
 *
 */

#ifndef n8_cControllable_Coponent_h
#define n8_cControllable_Coponent_h

#include "Component.h"

/** Used to indicate that an entity can be controlled be a user */
class Controllable_Coponent : public Component{
    
private:
    
public:
    Controllable_Coponent(string newID);
    
};

#endif
