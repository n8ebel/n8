/*
 * cMessage_Handler.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

#ifndef cmessage_handler_h
#define cmessage_handler_h

#include "cEntity.h"
#include <string>

using namespace std;

class cMessage_Handler{

private:
    
public:
    
    ~cMessage_Handler();
    cMessage_Handler();
    
    bool send_message(string systemID, int entity1, int entity2);
};


#endif