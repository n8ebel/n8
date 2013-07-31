/*
 * cSprite.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/30/13
 * Organization:    n8Tech
 *
 */

#ifndef CSPRITE_H
#define CSPRITE_H

#include "SDL/SDL.h"
#include <string>

using namespace std;

class cSprite {

private:
	string ID;
	SDL_Surface* image;

public:
	~cSprite();
	cSprite();
	cSprite(string id, SDL_Surface* img);

	string get_id();
	SDL_Surface* get_sprite();
	int get_height();
	int get_width();
};

#endif CSPRITE_H
