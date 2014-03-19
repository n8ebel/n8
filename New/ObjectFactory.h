/*
 *  ObjectFactory.h
 *  goobar
 *
 *  Created by Nate Ebel on 3/18/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#ifndef OBJECT_FACTORY_H
#define OBJECT_FACTORY_H

#include <iostream>

namespace n8{
    
class ObjectFactory{
public:
    static int m_nextId; /** < Static counter to get available id values for created entities **/
    
    ObjectFactory();
    ~ObjectFactory();
    
    int GetNextId();
    
private:
};

}

#endif /* defined(OBJECT_FACTORY_H) */
