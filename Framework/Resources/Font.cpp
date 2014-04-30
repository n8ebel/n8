//
//  Font.cpp
//  DevApp
//
//  Created by Nate Ebel on 4/17/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#include "Font.h"

#define TAG "Font"

n8::Font::Font(std::string p_id, TTF_Font* p_ttfFont) : m_id(p_id),
                                                        Resource(p_id),
                                                        m_font(p_ttfFont)
{

}

n8::Font::~Font(){
    if (m_font) {
       // Log::Debug(TAG, "Deleting font: " + m_id);
        TTF_CloseFont(m_font);
        m_font = nullptr;
    }
}

TTF_Font* n8::Font::GetFont(){
    return m_font;
}