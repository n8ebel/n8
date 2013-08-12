/*
 * Sprite.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/30/13
 * Organization:    n8Tech
 *
 */

#include "Sprite.h"


/** Default Destructor <p>
 *  Frees the loaded SDL_Surface which is pointed to by image_
 */
Sprite::~Sprite() {
	SDL_FreeSurface( image_ );
    
}

/** Constructor <p>
 *  Initializes id_ and image_ to passed values
 *
 *  @param id The unique identifier for the sprite.
 *  @param img The SDL_Surface to store in the sprite object
 */
Sprite::Sprite(string id, SDL_Surface* img){
	id_ = id;
	image_ = img;
	
}
