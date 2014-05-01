//
//  Rectangle.cpp
//  DevApp
//
//  Created by Nate Ebel on 4/28/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#include "Rectangle.h"

#define TAG "Rectangle"

/** Default Constructor **/
n8::Rectangle::Rectangle(){
    
}

/** Constructor
 *
 *  @param p_x The x coordinate of the rectangle
 *  @param p_y The y coordinate of the rectangle
 *  @param p_w The width of the rectangle
 *  @param p_h The height of the rectangle
 */
n8::Rectangle::Rectangle(int p_x, int p_y, int p_w, int p_h){
    m_rectangle.x = p_x;
    m_rectangle.y = p_y;
    m_rectangle.w = p_w;
    m_rectangle.h = p_h;
}

/** Default Destructor **/
n8::Rectangle::~Rectangle(){
    
}

/** Resizes the rectangle to the specified coordinates
 *
 *  @param p_w The new width of the rectangle
 *  @param p_h The new height of the rectangle
 */
void n8::Rectangle::Resize(int p_width, int p_height){
    m_rectangle.w = p_width;
    m_rectangle.h = p_height;
}

/** Offsets the rectangle by the specified amount
 *
 *  @param p_xOffset The horizontal amount to offset the position by
 *  @param p_yOffset The vertical amount to offset the position by
 */
void n8::Rectangle::Offset(int p_xOffset, int p_yOffset){
    m_rectangle.x += p_xOffset;
    m_rectangle.y += p_yOffset;
}

/** Repositions and resizes the rectangle using the specified inputs
 *
 *  @param p_x The new x coordinate of the rectangle
 *  @param p_y The new y coordinate of the rectaingle
 *  @param p_w The new width of the rectangle
 *  @param p_h The new height of the rectangle
 */
void n8::Rectangle::RepositionAndResize(int p_x, int p_y, int p_w, int p_h){
    m_rectangle.x = p_x;
    m_rectangle.y = p_y;
    m_rectangle.w = p_w;
    m_rectangle.h = p_h;
}

/** Returns the x position of the rectangle
 *
 *  @return The x coordinate of the rectangle
 */
int n8::Rectangle::GetX(){
    return m_rectangle.x;
}

/** Returns the y position of the rectangle
 *
 *  @return The y coordinate of the rectangle
 */
int n8::Rectangle::GetY(){
    return m_rectangle.y;
}

/** Returns the width position of the rectangle
 *
 *  @return The width of the rectangle
 */
int n8::Rectangle::GetW(){
    return m_rectangle.w;
}

/** Returns the height of the rectangle
 *
 *  @return The height of the rectangle
 */
int n8::Rectangle::GetH(){
    return m_rectangle.h;
}

/** Returns a pointer to the SDL_Rect member variable.
 *  Needed to give access to SDL_Rect pointer to SDL functions.
 *
 *  @return Pointer to the SDL_Rect member variable
 */
SDL_Rect* n8::Rectangle::GetRect(){
    return &m_rectangle;
}
