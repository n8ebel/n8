/*
 *  Color.cpp
 *  goobar
 *
 *  Created by Nate Ebel on 4/28/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#include "Color.h"

/** Default Constructor **/
n8::Color::Color()
{
    
}

/** Constructor
 *
 *  @param p_r The red value of the color
 *  @param p_g The green value of the color
 *  @param p_b The blue value of the color
 */
n8::Color::Color(int p_r, int p_g, int p_b){
    m_color.r = p_r;
    m_color.g = p_g;
    m_color.b = p_b;
}

/** Constructor
 *
 *  @param p_r The red value of the color
 *  @param p_g The green value of the color
 *  @param p_b The blue value of the color
 *  @param p_a The alpha value of the color
 */
n8::Color::Color(int p_r, int p_g, int p_b, int p_a){
    m_color.r = p_r;
    m_color.g = p_g;
    m_color.b = p_b;
    m_color.a = p_a;
}

/** Changes the color to the specified values
 *
 *  @param p_r The new red value
 *  @param p_g The new green value
 *  @param p_b The new blue value
 */
void n8::Color::Set(int p_r, int p_g, int p_b){
    m_color.r = p_r;
    m_color.g = p_g;
    m_color.b = p_b;
}

/** Changes the color to the specified values
 *
 *  @param p_r The new red value
 *  @param p_g The new green value
 *  @param p_b The new blue value
 *  @param p_a The new alpha value
 */
void n8::Color::Set(int p_r, int p_g, int p_b, int p_a){
    m_color.r = p_r;
    m_color.g = p_g;
    m_color.b = p_b;
    m_color.a = p_a;
}

/** Changes the red value of the color
 *
 *  @param p_r The new red value
 */
void n8::Color::SetR(int p_r){
    m_color.r = p_r;
}

/** Changes the green value of the color
 *
 *  @param p_g The new green value
 */
void n8::Color::SetG(int p_g){
    m_color.g = p_g;
}

/** Changes the blue value of the color
 *
 *  @param p_r The new blue value
 */
void n8::Color::SetB(int p_b){
    m_color.b = p_b;
}

/** Changes the alpha value of the color
 *
 *  @param p_r The new alpha value
 */
void n8::Color::SetA(int p_a){
    m_color.a = p_a;
}

/** Returns the red value of the color
 *
 *  @return m_r The red value of the color
 */
int n8::Color::GetR(){
    return m_color.r;
}

/** Returns the green value of the color
 *
 *  @return m_g The green value of the color
 */
int n8::Color::GetG(){
    return m_color.g;
}

/** Returns the blue value of the color
 *
 *  @return m_b The blue value of the color
 */
int n8::Color::GetB(){
    return m_color.b;
}

/** Returns the alpha value of the color
 *
 *  @return m_a The alpha value of the color
 */
int n8::Color::GetA(){
    return m_color.a;
}

SDL_Color n8::Color::GetColor(){
    return m_color;
}