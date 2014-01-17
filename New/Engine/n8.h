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

#include "GameManager.h"
#include "StateManager.h"
#include "EventManager.h"
#include "InputManager.h"
#include "ResourceManager.h"
#include "WindowManager.h"

#include "Render_System.h"

class n8{

public:
    
    n8();
    
    
    static bool Setup();
    static bool Shutdown();

    
};

#endif 
