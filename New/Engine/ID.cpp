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
    id_ = newID;
    
}

/** @return The value of the id */
int ID::get_id(){
    return id_;
}

bool operator== (ID &id1, ID &id2)
{
    return id1.get_id() == id2.get_id();
}

bool operator!= (ID &id1, ID &id2)
{
    return !(id1 == id2);
}