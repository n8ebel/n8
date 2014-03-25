//
//  TestState2.cpp
//  goobar
//
//  Created by Nate Ebel on 3/21/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#include "TestState2.h"

#include "ServiceManager.h"
#include "ResourceManagerService.h"

TestState2::TestState2() {
    //m_id = new ID(GAME_STATE);
    
    CreateSystems();
    CreateEntities();
}

TestState2::~TestState2(){
    
}



void TestState2::OnResume(){
    SDL_WM_SetCaption("Game State", "Game State");
}
void TestState2::OnPause(){
    
}

void TestState2::Update(Uint32 currentTime){
    
}
void TestState2::Render(SDL_Surface* screen){
    assert(screen);
    
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0,200,0));
    
    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;
    
    //Give the offsets to the rectangle
    offset.x = 25;
    offset.y = 25;
	
    SDL_Surface* img = static_cast<n8::ResourceManagerService*>(n8::ServiceManager::GetInstance()->GetService(EService::Resources))->LoadImage("/Users/lcballa44/Projects/n8/Game/gfx/sayain2.png");
    
    //Blit the surface
    SDL_BlitSurface( img, NULL, screen, &offset );
    
    
    
    SDL_Flip(screen);
    
    
}

void TestState2::RegisterEntity(Entity* newEntity){
    //m_stateEntities.push_back(newEntity);
}

void TestState2::CreateSystems(){
    //SystemManager::GetInstance()->RegisterSystem(RENDER_SYSTEM, new RenderSystem());
}

void TestState2::CreateEntities(){
    
    
}