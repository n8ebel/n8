/*
 * cDrawable_Component.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/29/13
 * Organization:    n8Tech
 *
 */

#ifndef n8_cDrawable_Component_h
#define n8_cDrawable_Component_h

#include "cComponent.h"
#include "cSprite.h"
#include <string>

class cDrawable_Component : public cComponent {

private:
    cSprite* sprite;
    
public:
    
    cDrawable_Component();
    ~cDrawable_Component();
    
    cDrawable_Component(string newID, cSprite* newSprite);
    
    cSprite* get_sprite();
    cSprite* set_sprite(cSprite* newSprite);
    
    
};

#endif
