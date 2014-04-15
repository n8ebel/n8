/*
 *  Resource.h
 *  n8
 *
 *  Created by Nate Ebel on 4/14/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>


namespace n8Tech {


class Resource{
public:
    Resource(std::string p_id){m_id = p_id;}
    virtual ~Resource() = 0;
    
    
private:
    std::string m_id;
    
};

}



#endif
