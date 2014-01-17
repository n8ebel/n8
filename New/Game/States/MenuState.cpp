/*
 * MenuState.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            12/22/13
 * Organization:    n8Tech
 *
 */

#include "MenuState.h"
#include "StateManager.h"
#include "EventManager.h"
#include "ExitStateEvent.h"


#include <iostream>

using namespace std;


MenuState::MenuState()  {
    m_id = new ID<int>(MENU_STATE);
    
    CreateSystems();
    
}

MenuState::~MenuState(){
    
}



void MenuState::OnResume(){
    SDL_WM_SetCaption("Menu State", "Menu State");
}
void MenuState::OnPause(){
    
}


void MenuState::RespondToUserInput(){
    if(InputManager::GetInstance()->KeyIsDown(SDLK_ESCAPE)){
        EventManager::GetInstance()->QueueEvent(new ExitStateEvent());
    }
}

void MenuState::Update(Uint32 currentTime){
    
}

void MenuState::Render(SDL_Surface* img){
    SDL_FillRect(img, NULL, SDL_MapRGB(img->format, 0,255,0));
    SDL_Flip( img );
}



void MenuState::CreateSystems(){
    Log::Info("Menu State", "Create Systems");
}

