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
#include "Component.h"

using namespace std;

/** Generic class to represent all game objects.  Entities can be differentiated
 *  by adding different components to customize them to meet specific needs.
 *  Everything from an in-game item to the game's screen is represented by an entity.
 */
class Entity{
 private:
    int id_; /** < a unique specifier for the entity **/
    map<string, Component*> component_map_;  /** < Stores all components added to the entity **/

 public:
    ~Entity();
    
    /** Constructor <p>
     *  Used to create a new entity object
     *  Creates a new entity and sets its id value
     *
     *  @param newId the unique id specifier for the new entity
     */
    explicit Entity(int newId) { id_ = newId;}
  
    void add_component(Component* newComponent);
    void remove_component(string componentID);
  
    /** 
     *  
     *  @return the integer id of the entity
     */
    int get_id() { return id_;}
    
    Component* get_component(string componentID);
    map<string,Component*> get_components();
};

#endif 
