/*
 * Size_Component.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            8/6/13
 * Organization:    n8Tech
 *
 */

#ifndef n8_Size_Component_h
#define n8_Size_Component_h

#include "Component.h"

class Size_Component : public Component{

private:
    int width_;
    int height_;
    
public:
    ~Size_Component();
    Size_Component();
    Size_Component(string newID, int w, int h);
    
    
    int get_width();
    int get_height();
    
};


#endif
