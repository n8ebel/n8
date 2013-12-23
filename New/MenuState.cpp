//
//  MenuState.cpp
//  goobar
//
//  Created by Nate Ebel on 12/22/13.
//  Copyright (c) 2013 n8Tech. All rights reserved.
//

#include "MenuState.h"

MenuState::MenuState() {
    
}

MenuState::~MenuState(){
    
}

void MenuState::update(Uint32 currentTime){
    std::cout << "MenuState.update()" << std::endl;
}
void MenuState::render(SDL_Surface* img){
    std::cout << "MenuState.render()" << std::endl;
    SDL_FillRect(img, NULL, SDL_MapRGB(img->format, 0,255,0));
    SDL_Flip( img );
}