/*
 * cSprite.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/30/13
 * Organization:    n8Tech
 *
 */

#include "cSprite.h"

cSprite::cSprite() {
	ID = "NO_ID";
	image = NULL;
	
}

cSprite::~cSprite() {
	SDL_FreeSurface( image );
    
}

cSprite::cSprite(string id, SDL_Surface* img){
	ID = id;
	image = img;
	
}

/** get_id
 *
 *  Use-    returns the string specifier for the image
 *
 */
string cSprite::get_id(){
	return ID;
}


SDL_Surface* cSprite::get_image(){
	return image;
}

int cSprite::get_height(){
	return image->h;
}

int cSprite::get_width(){
	return image->w;
}
