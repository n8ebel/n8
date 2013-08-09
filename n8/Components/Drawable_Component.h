/*
 * Drawable_Component.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/29/13
 * Organization:    n8Tech
 *
 */

#ifndef n8_Drawable_Component_h
#define n8_Drawable_Component_h

#include "Component.h"
#include "Sprite.h"
#include <string>

class Drawable_Component : public Component {

private:
    Sprite* sprite_;
    
public:
    
    Drawable_Component();
    ~Drawable_Component();
    
    Drawable_Component(string newID, Sprite* newSprite);
    
    SDL_Surface* get_image();
    Sprite* get_sprite();
    Sprite* set_sprite(Sprite* newSprite);
    
    
};

#endif
