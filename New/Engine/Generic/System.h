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

#include "Entity.h"

#include <string>
#include <map>
#include <vector>

namespace n8{
/** Base system used to derive other game systems.  A system operates on entities
 *  that meet a set of defined component requirements.  This ensures that only
 *  entities that have the neccessary types of data are operated on.
 */
class System {
public:
    ~System();
    System();
    
    virtual void Update() = 0;

    virtual bool RegisterEntity(entities::Entity*) = 0;
    virtual void UnregisterEntity(entities::Entity*) = 0;
    
protected:
    map<ID,int> m_systemRequirements;          /** < A map of the required components to be registered with
                                             and be operated on by this system **/
    map<ID, n8::entities::Entity*> m_registeredEntities;   /** < Stores pointers to all entities that meet the system  requirements and have been registered with the system **/
    
    ID m_id;     /** < Unique identifier for the system to indicate what type of system it is **/
    
    bool CheckRequirements(entities::Entity* entity);

};
    
} //namespace n8

#endif
