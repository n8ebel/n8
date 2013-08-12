/*
 * System.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

#ifndef n8_System_h
#define n8_System_h

#include "Message_handler.h"
#include "Entity.h"
#include "constants.h"

#include <string>
#include <map>
#include <vector>

using namespace std;

class System {
  public:
    ~System();
    System();
    
    /** Used to store a pointer to a message handler so it can be used to pass messages
     *  to other game systems and to the game manager
     *
     *  @param msgr A pointer to a Message_Handler object
     */
    void connect_message_handler_(Message_Handler* msgr) { message_system_ = msgr; }

    bool register_entity(Entity* newEntity);
    virtual void update();
    
  protected:
    map<string,int> requirements_;          /** < A map of the required components to be registered with
                                             and be operated on by this system **/
    
    vector<Entity*> registered_entities_;   /** < Stores pointers to all entities that meet the system  requirements and have been registered with the system **/
    
    Message_Handler* message_system_;       /** < Pointer to a Message_Handler so messages can be passed to game systems **/
    
    string id_;     /** < Unique identifier for the system to indicate what type of system it is **/
    
    bool check_requirements(Entity* entity);    
    

};

#endif
