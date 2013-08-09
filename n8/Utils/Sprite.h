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
#include <string>

using namespace std;

class Sprite {

private:
	string id_;
	SDL_Surface* image_;

public:
	~Sprite();
	Sprite();
	Sprite(string id, SDL_Surface* img);

	string get_id();
	SDL_Surface* get_image();
	int get_height();
	int get_width();
};

#endif 
