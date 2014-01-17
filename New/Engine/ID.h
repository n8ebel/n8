/*
 * ID.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            12/22/13
 * Organization:    n8Tech
 *
 */

#ifndef ID_H
#define ID_H

#include <iostream>
using namespace std;

/** Handles id abstraction */
template <class T>
class ID{
public:
    ID(T newID) {m_id = newID;};
    
    T GetId() {return m_id;};
    
   
    
private:
    T m_id; /** < Actual id value **/
};




#endif