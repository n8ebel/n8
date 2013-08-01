/*
 * cSystem.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

#ifndef n8_cSystem_h
#define n8_cSystem_h

#include "cMessage_Handler.h"
#include "cEntity.h"
#include "constants.h"

#include <string>
#include <map>
#include <vector>

using namespace std;

class cSystem {
protected:
    
    
    map<string,int> requirements;
    vector<cEntity*> registered_entities;
    cMessage_Handler* message_system;
    
    string ID;
    
    bool check_requirements(cEntity* entity);
    
public:
    ~cSystem();
    cSystem();
    
    void connect_message_handler(cMessage_Handler* msgr);
    
    bool register_entity(cEntity* newEntity);
    
    virtual void update();
};

#endif
