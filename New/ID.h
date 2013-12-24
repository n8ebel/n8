//
//  ID.h
//  goobar
//
//  Created by Nate Ebel on 12/23/13.
//  Copyright (c) 2013 n8Tech. All rights reserved.
//

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