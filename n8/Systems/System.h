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
protected:
    
    
    map<string,int> requirements_;
    vector<Entity*> registered_entities_;
    Message_Handler* message_system_;
    
    string id_;
    
    bool check_requirements(Entity* entity);
    
public:
    ~System();
    System();
    
    void connect_message_handler_(Message_Handler* msgr);
    
    bool register_entity(Entity* newEntity);
    
    virtual void update();
};

#endif
