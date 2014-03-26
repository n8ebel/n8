/*
 * SystemManager.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            1/17/14
 * Organization:    n8Tech
 *
 */

#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H

#include "System.h"
#include "Singleton.h"
#include "Object.h"


#include <map>

using namespace std;

class SystemManager :public Singleton<SystemManager>,Object{

public:
    SystemManager();
    ~SystemManager();
    
    bool RegisterSystem(string, System*);
    void UnregisterSystem(string);
    
    void RegisterEntity(Entity*);
    void UnregisterEntity(Entity*);
    
    void Update(Uint32);
    
    System* GetSystem(string);
    
private:
    map<string, System*> m_registeredSystems; /** < Stores pointers to registered game systems */
    
};

#endif
