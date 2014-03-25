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
    SDL_WM_SetCaption("Game State", "Game State");
}
void TestState::OnPause(){
    
}

void TestState::Update(Uint32 currentTime){
   
}
void TestState::Render(SDL_Surface* screen){
    assert(screen);
    
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 200,0,0));
   
    
    SDL_Flip(screen);
    
    
}

void TestState::RegisterEntity(Entity* newEntity){
    //m_stateEntities.push_back(newEntity);
}

void TestState::CreateSystems(){
    //SystemManager::GetInstance()->RegisterSystem(RENDER_SYSTEM, new RenderSystem());
}

void TestState::CreateEntities(){
    

}
