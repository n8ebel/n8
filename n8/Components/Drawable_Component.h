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
    Sprite* sprite_;    /** < The sprite to use to draw */
    
public:
    
    ~Drawable_Component();
    Drawable_Component(string newID, Sprite* newSprite);
    
    /** Used to get the SDL_Surface stored by the sprite that can be drawn to the screen
     *
     *  @return The SDL_Surface stored by sprite_
     *
     *  @see Sprite
     *  @see Component
     */
    SDL_Surface* get_image() { return sprite_->get_image(); }
    
    /** Used to get the sprite object of the component
     *
     *  @return The sprite held by the component (sprite_)
     *
     *  @see Sprite
     */
    Sprite* get_sprite() { return sprite_; }
    
    /** Used to set the sprite held by the component.  This allows an entity to change the sprite used to draw it.
     *
     *  @param newSprite The new sprite to be used by the component
     *
     *  @see Sprite
     */
    Sprite* set_sprite(Sprite* newSprite) { sprite_ = newSprite; return sprite_; }
    
    
};

#endif
