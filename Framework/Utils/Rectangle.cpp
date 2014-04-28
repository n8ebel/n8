//
//  Rectangle.cpp
//  DevApp
//
//  Created by Nate Ebel on 4/28/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#include "Rectangle.h"

n8::Rectangle::Rectangle(){
    
}

n8::Rectangle::Rectangle(int p_x, int p_y, int p_w, int p_h){
    m_rectangle.x = p_x;
    m_rectangle.y = p_y;
    m_rectangle.w = p_w;
    m_rectangle.h = p_h;
}

n8::Rectangle::~Rectangle(){
    
}

void n8::Rectangle::Resize(int p_x, int p_y, int p_w, int p_h){
    m_rectangle.x = p_x;
    m_rectangle.y = p_y;
    m_rectangle.w = p_w;
    m_rectangle.h = p_h;
}

void n8::Rectangle::Offset(int p_xOffset, int p_yOffset){
    m_rectangle.x += p_xOffset;
    m_rectangle.y += p_yOffset;
}

int n8::Rectangle::GetX(){
    return m_rectangle.x;
}
int n8::Rectangle::GetY(){
    return m_rectangle.y;
}
int n8::Rectangle::GetW(){
    return m_rectangle.w;
}
int n8::Rectangle::GetH(){
    return m_rectangle.h;
}
SDL_Rect* n8::Rectangle::GetRect(){
    return &m_rectangle;
}
