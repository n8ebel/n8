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

class Component {
 private:
  string id_;   /** < The identifier for the component **/

 public:

    ~Component();
    
    /** Constructor <p>
     */
    Component(string newID) { id_ = newID; }

    /** Used to get the identifier of the component
     *
     *  @return The identifier of the component
     */
    string get_id() { return id_; }

};

#endif 
