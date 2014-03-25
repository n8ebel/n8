/*
 * GameState.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            12/22/13
 * Organization:    n8Tech
 *
 */

#include <iostream>

#include "TestState.h"

using namespace std;

TestState::TestState() {
    //m_id = new ID(GAME_STATE);
    
    CreateSystems();
    CreateEntities();
}

TestState::~TestState(){
    
}



void TestState::OnResume(){
    
}
void TestState::OnPause(){
    
}

void TestState::Update(Uint32 currentTime){
   
}
void TestState::Render(SDL_Window* p_window){
   // assert(screen);
    
    SDL_FillRect(SDL_GetWindowSurface(p_window), NULL, SDL_MapRGB(SDL_GetWindowSurface(p_window)->format, 200,0,0));
   
    
    //SDL_Flip(screen);
    
    //Update the surface
    SDL_UpdateWindowSurface( p_window );
    
}

void TestState::RegisterEntity(Entity* newEntity){
    //m_stateEntities.push_back(newEntity);
}

void TestState::CreateSystems(){
    //SystemManager::GetInstance()->RegisterSystem(RENDER_SYSTEM, new RenderSystem());
}

void TestState::CreateEntities(){
    

}
