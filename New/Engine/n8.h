/*
 * Sprite_Manager.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */  

#ifndef N8_H
#define N8_H

#include "Managers/Game_Manager.h"
#include "State_Manager.h"
#include "Event_Manager.h"
#include "Input_Manager.h"

class n8{

public:
    
    n8();
    
    
    static bool setup_n8();
    static bool shutdown_n8();

    
};

#endif 
