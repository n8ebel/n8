/*
 * message_handler_.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

#ifndef message_handler__h
#define message_handler__h

#include "Entity.h"
#include <string>

using namespace std;

class Message_Handler{

private:
    
public:
    
    ~Message_Handler();
    Message_Handler();
    
    bool send_message(string systemID, int entity1, int entity2);
};


#endif