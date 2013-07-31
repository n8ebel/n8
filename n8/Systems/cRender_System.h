/*
 * cRender_System.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/30/13
 * Organization:    n8Tech
 *
 */

#ifndef n8_cRender_System_h
#define n8_cRender_System_h

#include "cSystem.h"

class cRender_System : public cSystem {

private:
    
public:
    ~cRender_System();
    cRender_System();
    
    void update();
    void render();
    
};


#endif
