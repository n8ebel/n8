/*
 * Sprite.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/30/13
 * Organization:    n8Tech
 *
 */

#ifndef Sprite_H
#define Sprite_H

#include "SDL/SDL.h"
#include "SDL_image/SDL_image.h"

#include <string>

using namespace std;

/** An object to hold an optimzed SDL_Surface image and provide access to it **/
class Sprite {

private:
	string id_;     /** < A unique identifier for the object.  It could be the file name or the filepath **/
	SDL_Surface* image_;  /** < The image that can be drawn to a canvas  **/
    
public:
	~Sprite();
	Sprite(string id, SDL_Surface* img);

    /** Used to get the unique specifier for the sprite object 
     *
     *  @return The unique specifier
     */
	string get_id() { return id_; }
    
    /** Used to get the image stored in the sprite so it can be drawn to the screen
     *
     *  @return The SDL_Surface stored with image_
     */
	SDL_Surface* get_image() {return image_;}
    
    /** Used to get the height of the sprite image
     *
     *  @return The height of the SDL_Surface referenced by image_
     */
	int get_height() { return image_->h; }
    
    /** Used to get the width of the sprite image
     *
     *  @return The width of the SDL_Surface referenced by image_
     */
	int get_width() { return image_->w; }
	
	bool draw( int x, int y, SDL_Surface* destination );
	bool draw( int x, int y, int x2, int y2, int width, int height, SDL_Surface* dest);
};

#endif 
