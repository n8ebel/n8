/*
 * message_handler_.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

#include "Message_Handler.h"
#include <iostream>

using namespace std;

/** Default Destructor **/
Message_Handler::~Message_Handler(){
    
}

/** Default Constructor **/
Message_Handler::Message_Handler(){
    
}

/** Sends a message to a specifed system about two entities
 *
 *  @param systemID the id specifier for the system to send the mssage to
 *  @param entity1 the first entity involved in the message
 *  @param entity2 the first entity involved in the message
 *
 *  @return True if the message was successfully passed, False otherwise
 */
bool Message_Handler::send_message(string systemID, int entity1, int entity2){
    
    return true;
}