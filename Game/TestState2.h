//
//  TestState2.h
//  goobar
//
//  Created by Nate Ebel on 3/21/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#ifndef __goobar__TestState2__
#define __goobar__TestState2__

#include <iostream>

#include "State.h"

class Entity;

class TestState2 : public n8::State {
public:
    TestState2();
    virtual ~TestState2();
    
    virtual void OnResume();
    virtual void OnPause();
    
    virtual void Update(Uint32 currentTime);
    virtual void Render(n8::Window* img);
    
    virtual void RegisterEntity(Entity* newEntity);
    
private:
    virtual void CreateSystems();
    virtual void CreateEntities();
    
};

#endif /* defined(__goobar__TestState2__) */
