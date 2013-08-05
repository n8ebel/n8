/*
 * cMovement_System.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            8/4/13
 * Organization:    n8Tech
 *
 */

#ifndef n8_cMovement_System_h
#define n8_cMovement_System_h

#include "cSystem.h"

class cMovement_System : public cSystem{
   
private:
    
public:
    
    ~cMovement_System();
    cMovement_System();
    
    void update();
    
    void key_right();
    void key_down();
    void key_left();
    void key_up();

};

#endif
