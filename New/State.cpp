#include "State.h"

#include <iostream>

State::State(){

}

State::~State(){
    
}


void State::update(Uint32 currentTime){
    std::cout << "State.update()" << std::endl;
}
void State::render(SDL_Surface* img){
     std::cout << "State.render()" << std::endl;
    SDL_FillRect(img, NULL, SDL_MapRGB(img->format, 0,255,0));
    SDL_Flip( img );
}