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

/** Draws the sprite image to a destination SDL_Surface.
 *
 *  @param x The x location where the source SDL_Surface should be drawn
 *  @param y The y location where the source SDL_Surface should be drawn
 *  @param destination The canvas SDL_Surface that images are drawn to
 */
bool Sprite::draw( int x, int y, SDL_Surface* destination )
{
	if( image_ == NULL || destination == NULL){
		return false;
	}
	
    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;
    
    //Give the offsets to the rectangle
    offset.x = x;
    offset.y = y;
	
    
    //Blit the surface
    SDL_BlitSurface( image_, NULL, destination, &offset );
	
	return true;
}

/** Used to draw a section of the sprite image to the screen.  The size of the sub-image is given
 *	along with the coordinates in the source image to take the sub image from.  Specifying
 *  x2 = 0, y2=0, width = 50, height=50 would take the top left 50x50 portion of the source image.
 *
 *  @param x The x location where the sub-image should be drawn
 *  @param y The y location where the sub-image should be drawn
 *  @param x2 The x location for the sub-image to be taken from the source image
 *  @param y2 The y location for the sub-image to be taken from the source image
 *	@param width The width of the sub-image
 *	@param height The height of the sub-image
 *  @param destination The canvas SDL_Surface that images are drawn to
 */
bool Sprite::draw( int x, int y, int x2, int y2, int width, int height, SDL_Surface* destination){

	if( image_ == NULL || destination == NULL){
		return false;
	}
	
    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;
    
    //Give the offsets to the rectangle
    offset.x = x;
    offset.y = y;
	
	SDL_Rect srcR;
	
	srcR.x = x2;
	srcR.y = y2;
	srcR.w = width;
	srcR.h = height;
	
	
    
    //Blit the surface
    SDL_BlitSurface( image_, &srcR, destination, &offset );
	
	return true;
}