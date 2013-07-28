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

#include <string>
#include <map>
#include <vector>

using namespace std;

class cSystem {
private:
    map<string,int> requirements;
    vector<int> registered_entities;
    cMessage_Handler* message_system;
    
    const string ID = "BASE_SYSTEM";
    
public:
    ~cSystem();
    cSystem();
    
    bool check_requirements(cEntity* entity);
    void register_entity(cEntity* newEntity);
    
    virtual void update() = 0;
};

#endif
