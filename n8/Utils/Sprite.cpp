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

Sprite::Sprite() {
	id_ = "NO_ID";
	image_ = NULL;
	
}

Sprite::~Sprite() {
	SDL_FreeSurface( image_ );
    
}

Sprite::Sprite(string id, SDL_Surface* img){
	id_ = id;
	image_ = img;
	
}

/** get_id
 *
 *  Use-    returns the string specifier for the image
 *
 */
string Sprite::get_id(){
	return id_;
}


SDL_Surface* Sprite::get_image(){
	return image_;
}

int Sprite::get_height(){
	return image_->h;
}

int Sprite::get_width(){
	return image_->w;
}
