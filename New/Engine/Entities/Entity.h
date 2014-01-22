/*
 * Entity.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

#ifndef Entity_H
#define Entity_H

#include <vector>
#include <map>
#include <string>

#include "Object.h"
#include "Component.h"

using namespace std;

/** Generic class to represent all game objects.  Entities can be differentiated
 *  by adding different components to customize them to meet specific needs.
 *  Everything from an in-game item to the game's screen is represented by an entity.
 */
class Entity : public Object{
 public:
    ~Entity();
    
    /** Constructor <p>
     *  Used to create a new entity object
     *  Creates a new entity and sets its id value
     *
     *  @param newId the unique id specifier for the new entity
     *  @param newType the type specifier for the new entity
     */
    explicit Entity(ID* newId, string newType) { m_id = newId; m_type = newType; }
  
    void AddComponent(Component* newComponent);
    void RemoveComponent(string componentID);
  
    /** 
     *  
     *  @return the integer id of the entity
     */
    ID GetId() { return *m_id;}
    
    /** Gets the type of the entity
     *
     *  @return The string type identifier
     */
    string GetType() { return m_type; }

    Component* GetComponent(ID componentID);
    map<ID,Component*> GetComponents();
    
  private:
    ID* m_id; /** < a unique specifier for the entity **/
    string m_type;  /** < an identifier so entities can be grouped together.  ex: NPC, Enemy, User **/
    map<ID, Component*> m_componentMap;  /** < Stores all components added to the entity **/

};

#endif 
