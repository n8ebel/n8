//
//  Font.cpp
//  DevApp
//
//  Created by Nate Ebel on 4/17/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#include "Font.h"

n8::Font::Font(std::string p_id, TTF_Font* p_ttfFont) : Resource(p_id){
    
    p_font = p_ttfFont;
    
}

n8::Font::~Font(){
    TTF_CloseFont(p_font);
    p_font = NULL;
}