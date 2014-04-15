/*
 * Sprite.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            4/14/14
 * Organization:    n8Tech
 *
 */

#ifndef SPRITE_H
#define SPRITE_H

#include <string>

#include "Resource.h"

namespace n8{

/** An object to hold an optimzed SDL_Surface image and provide access to it **/
class Sprite :public Resource{
public:
	~Sprite();
	Sprite(std::string p_id, SDL_Surface* p_img);
    
    
    /** Used to get the image stored in the sprite so it can be drawn to the screen
     *
     *  @return The SDL_Surface stored with image_
     *
	SDL_Surface* get_image() {return m_image;}
    */
    
    /** Used to get the height of the sprite image
     *
     *  @return The height of the SDL_Surface referenced by image_
     */
	int get_height() { return m_image->h; }
    
    /** Used to get the width of the sprite image
     *
     *  @return The width of the SDL_Surface referenced by image_
     */
	int get_width() { return m_image->w; }
	
	bool draw( int p_x, int p_y, SDL_Surface* p_destination );
	bool draw( int p_x, int p_y, int p_x2, int p_y2, int p_width, int p_height, SDL_Surface* p_dest);
    
private:
    
	SDL_Surface* m_image;  /** < The image that can be drawn to a canvas  **/
    
    friend class RenderService;
};

}
#endif
