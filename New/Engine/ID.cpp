/*
 * ID.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            12/22/13
 * Organization:    n8Tech
 *
 */

#include "ID.h"

/** Default constructor
 *
 *  @param newID the value for the id
 */
ID::ID(int newID){
    m_id = newID;
    
}

/** @return The value of the id */
int ID::GetId(){
    return m_id;
}

bool operator== (ID &id1, ID &id2)
{
    return id1.GetId() == id2.GetId();
}

bool operator!= (ID &id1, ID &id2)
{
    return !(id1 == id2);
}