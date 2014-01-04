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

class ID{
public:
    ID(int newID);
    
    int getID();
    
private:
    int id_;
};

#endif