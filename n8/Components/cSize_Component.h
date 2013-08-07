/*
 * cSize_Component.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            8/6/13
 * Organization:    n8Tech
 *
 */

#ifndef n8_cSize_Component_h
#define n8_cSize_Component_h

#include "cComponent.h"

class cSize_Component : public cComponent{

private:
    int width;
    int height;
    
public:
    ~cSize_Component();
    cSize_Component();
    cSize_Component(string newID, int w, int h);
    
    
    int get_width();
    int get_height();
    
};


#endif
