/*
 * n8.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */  

#ifndef N8_H
#define N8_H

#include "cGame_Manager.h"
#include "cEntity.h"
#include "cName_Component.h"
#include "cPosition_Component.h"
#include <string>

class n8{

 private:

 public:
    static int nextID;
    
    n8();
    
    
    static cEntity* create_user_entity(int id, string initName, int initX, int initY);
    static cName_Component* get_name_component(cEntity* entity);
    static cPosition_Component* get_position_component(cEntity* entity);
    
    static void log_error(string msg);
    static void log_info(string msg);

};

#endif 
