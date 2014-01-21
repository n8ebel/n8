/*
 * Object.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            8/15/13
 * Organization:    n8Tech
 *
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "SDL/SDL.h"
#include "SDL_image/SDL_image.h"
#include "SystemValues.h"
#include "Log.h"
#include <assert.h>

/** Generic base class */
class Object {
  private:

  public:
	Object() { }
	virtual ~Object() = 0;
    

};

inline Object::~Object() { }
#endif /* OBJECT_H */
