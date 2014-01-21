/*
 * GameState.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            12/22/13
 * Organization:    n8Tech
 *
 */

#include "GameState.h"
#include "StateManager.h"
#include "EventManager.h"
#include "WindowManager.h"
#include "ExitStateEvent.h"
#include "ShowMenuEvent.h"
#include "ResourceManager.h"
#include "SystemManager.h"

#include "Drawable_Component.h"
#include "Position_Component.h"

#include <iostream>

using namespace std;

GameState::GameState() {
    m_id = new ID<int>(GAME_STATE);
    
    CreateSystems();
    CreateEntities();
}

GameState::~GameState(){
    
}



void GameState::OnResume(){
    SDL_WM_SetCaption("Game State", "Game State");
}
void GameState::OnPause(){
    
}


void GameState::RespondToUserInput(){
    if(InputManager::GetInstance()->KeyIsDown(SDLK_ESCAPE)){
        EventManager::GetInstance()->QueueEvent(new ExitStateEvent());
    }
    
    if(InputManager::GetInstance()->KeyIsDown(SDLK_SPACE)){
        EventManager::GetInstance()->QueueEvent(new ShowMenuEvent());
    }
}

void GameState::Update(Uint32 currentTime){
   
}
void GameState::Render(SDL_Surface* screen){
    assert(screen);
   
    static_cast<RenderSystem*>(SystemManager::GetInstance()->GetSystem(RENDER_SYSTEM))->Render(screen);
}

void GameState::RegisterEntity(Entity* newEntity){
    m_entities.push_back(newEntity);
}

void GameState::CreateSystems(){
    SystemManager::GetInstance()->RegisterSystem(RENDER_SYSTEM, new RenderSystem());
}

void GameState::CreateEntities(){
    
    Entity* backgroundEntity = new Entity(0,PROJECTILE_TYPE);
    backgroundEntity->AddComponent(new Drawable_Component(DRAWABLE,ResourceManager::GetInstance()->GetSprite(BOARD_SPRITE)));
    backgroundEntity->AddComponent(new Position_Component(POSITION,0,0,630,540));
    SystemManager::GetInstance()->RegisterEntity(backgroundEntity);
    
    Entity* missileEntity = new Entity(1,PROJECTILE_TYPE);
    missileEntity->AddComponent(new Drawable_Component(DRAWABLE,ResourceManager::GetInstance()->GetSprite(HERO_SPRITE)));
    missileEntity->AddComponent(new Position_Component(POSITION,40,60,32,32));
    SystemManager::GetInstance()->RegisterEntity(missileEntity);
    
    

}
