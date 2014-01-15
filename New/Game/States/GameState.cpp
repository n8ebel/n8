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
#include "ExitStateEvent.h"
#include "ShowMenuEvent.h"
#include "ResourceManager.h"


#include <iostream>

using namespace std;

GameState::GameState()  {
    m_id = new ID(GAME_STATE);
    
}

GameState::~GameState(){
    
}

ID* GameState::GetId(){
    return m_id;
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
    SDL_FillRect(img, NULL, SDL_MapRGB(img->format, 255,0,0));
    
    SDL_Rect offset;
    
    //Give the offsets to the rectangle
    offset.x = 0;
    offset.y = 0;
	
    
    //Blit the surface
    SDL_BlitSurface( ResourceManager::GetInstance()->GetSprite("/Users/lcballa44/Projects/n8/Deprecated/Assets/gfx/missile.bmp")->get_image(), NULL, img, &offset );
    
    SDL_Flip( img );
}

void GameState::RegisterEntity(Entity* newEntity){
    
}
