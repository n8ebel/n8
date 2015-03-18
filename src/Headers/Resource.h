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

#include "/Library/Frameworks/SDL2.framework/Versions/A/Headers/SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"


namespace n8 {

    /** \class Resource
     *  \brief Base class for resource objects.
     */
class Resource{
public:
    Resource(std::string p_id){m_id = p_id;}
    virtual ~Resource(){};
    
    /**
     *  @return The string id of the resource
     */
    const std::string GetId() const {return m_id;}
    
private:
    std::string m_id; /** < The identifier of the resource > */
    
};

}



#endif
