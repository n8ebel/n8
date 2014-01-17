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
void GameState::Render(SDL_Surface* img){
    //SDL_FillRect(img, NULL, SDL_MapRGB(img->format, 255,0,0));
    
    SDL_Rect offset;
    
    //Give the offsets to the rectangle
    offset.x = 50;
    offset.y = 50;
	
    
    for (int i = 0; i < m_entities.size(); i++) {
        //Give the offsets to the rectangle
        offset.x = ((Position_Component*)m_entities[i]->GetComponent(POSITION))->get_left();
        offset.y = ((Position_Component*)m_entities[i]->GetComponent(POSITION))->get_top();

        
        //Blit the surfaces
        SDL_BlitSurface( ((Drawable_Component*)m_entities[i]->GetComponent(DRAWABLE))->get_image(), NULL, img, &offset );
    }
    
    m_renderSystem->Render(WindowManager::GetInstance()->GetScreenSurface());
    
    
    SDL_Flip( img );
}

void GameState::RegisterEntity(Entity* newEntity){
    m_entities.push_back(newEntity);
}

void GameState::CreateSystems(){
    m_renderSystem = new RenderSystem();
}

void GameState::CreateEntities(){
    
    Entity* backgroundEntity = new Entity(0,PROJECTILE_TYPE);
    backgroundEntity->AddComponent(new Drawable_Component(DRAWABLE,ResourceManager::GetInstance()->GetSprite("/Users/lcballa44/Projects/n8/Deprecated/Assets/gfx/background.bmp")));
    backgroundEntity->AddComponent(new Position_Component(POSITION,0,0,400,400));
    
    RegisterEntity(backgroundEntity);
    
    Entity* missileEntity = new Entity(1,PROJECTILE_TYPE);
    missileEntity->AddComponent(new Drawable_Component(DRAWABLE,ResourceManager::GetInstance()->GetSprite("/Users/lcballa44/Projects/n8/Deprecated/Assets/gfx/missile.bmp")));
    missileEntity->AddComponent(new Position_Component(POSITION,0,0,32,32));
    
    RegisterEntity(missileEntity);
    
    

}
