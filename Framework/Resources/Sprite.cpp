/*
 * Sprite.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            4/14/14
 * Organization:    n8Tech
 *
 */

#include "Sprite.h"
#include <assert.h>

namespace n8{

/** Default Destructor <p>
 *  Frees the loaded SDL_Surface which is pointed to by image_
 */
Sprite::~Sprite() {
    SDL_FreeSurface( m_image );
    
}

/** Constructor <p>
 *  Initializes id_ and image_ to passed values
 *
 *  @param id The unique identifier for the sprite.
 *  @param img The SDL_Surface to store in the sprite object
 */
Sprite::Sprite(std::string p_id, SDL_Surface* p_img) : Resource(p_id){
    
    assert(p_img);
	m_image = p_img;
	
}

/** Draws the sprite image to a destination SDL_Surface.
 *
 *  @param x The x location where the source SDL_Surface should be drawn
 *  @param y The y location where the source SDL_Surface should be drawn
 *  @param destination The canvas SDL_Surface that images are drawn to
 */
bool Sprite::Draw( int p_x, int p_y, SDL_Surface* p_destination )
{
    assert(m_image);
    assert(p_destination);
    
	if( m_image == NULL || p_destination == NULL){
		return false;
	}
	
    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;
    
    //Give the offsets to the rectangle
    offset.x = p_x;
    offset.y = p_y;
	
    
    //Blit the surface
    SDL_BlitSurface( m_image, NULL, p_destination, &offset );
	
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
bool Sprite::Draw( int p_x, int p_y, int p_x2, int p_y2, int p_width, int p_height, SDL_Surface* p_destination){

    assert(m_image);
    assert(p_destination);

	if( m_image == NULL || p_destination == NULL){
		return false;
	}
	
    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;
    
    //Give the offsets to the rectangle
    offset.x = p_x;
    offset.y = p_y;
	
	SDL_Rect srcR;
	
	srcR.x = p_x2;
	srcR.y = p_y2;
	srcR.w = p_width;
	srcR.h = p_height;
	
	
    
    //Blit the surface
    SDL_BlitSurface( m_image, &srcR, p_destination, &offset );
	
	return true;
}
}