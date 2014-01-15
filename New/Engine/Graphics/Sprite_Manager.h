/*
 * Sprite_Manager.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            8/14/13
 * Organization:    n8Tech
 *
 */

#ifndef SPRITE_MANAGER_H
#define SPRITE_MANAGER_H

#include <map>
#include <string>
#include <iostream>
#include <fstream>

#include "Sprite.h"

using namespace std;

class Sprite_Manager {
  public:
    Sprite_Manager();
    virtual ~Sprite_Manager();

    void load_images(string filepath);

    Sprite* get_sprite(string file);

  private:
    map<string,Sprite*> loaded_images_;  /** < Stores all images loaded by the system  ***/
    SDL_Surface* load_image(string filename);
};

#endif /* SPRITE_MANAGER_H */
