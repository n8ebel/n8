/*
 * Component.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            7/27/13
 * Organization:    n8Tech
 *
 */

#ifndef Component_H
#define Component_H

#include <string>

using namespace std;

/** Base class for all components.  Used to create new components to be used by entity objects
 *  Components contain all important data that an entity may want.  Entity data stored in components
 *  can be operated on by systems.
 */
class Component {
  public:
    virtual ~Component();
    
    /** Constructor <p>
     */
    Component(string newID) { id_ = newID; }

    /** Used to get the identifier of the component
     *
     *  @return The identifier of the component
     */
    string get_id() { return id_; }

  private:
    string id_;   /** < The identifier for the component **/
};

#endif 
