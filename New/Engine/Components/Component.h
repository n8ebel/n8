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

#include "Object.h"
#include "ID.h"
#include <string>

using namespace std;

/** Base class for all components.  Used to create new components to be used by entity objects
 *  Components contain all important data that an entity may want.  Entity data stored in components
 *  can be operated on by systems.
 */
class Component : public Object {
  public:
    virtual ~Component();
    
    /** Constructor <p>
     */
    Component() { m_id = new ID(COMPONENT_BASE); }

    /** Used to get the identifier of the component
     *
     *  @return The identifier of the component
     */
    ID GetId() { return *m_id; }

  protected:
    ID* m_id;   /** < The identifier for the component **/
};

#endif 
