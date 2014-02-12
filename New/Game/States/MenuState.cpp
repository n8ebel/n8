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
#include "ShowGameEvent.h"
#include "GameManager.h"
#include "ResourceManager.h"
#include "WindowManager.h"

#include "Drawable_Component.h"
#include "Position_Component.h"


#include <iostream>

using namespace std;


MenuState::MenuState()  {
    m_id = new ID(MENU_STATE);
    
    CreateSystems();
    CreateEntities();
    
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
    
    if(InputManager::GetInstance()->KeyIsDown(SDLK_SPACE)){
        EventManager::GetInstance()->QueueEvent(new ShowGameEvent());
    }
}

void MenuState::Update(Uint32 currentTime){
    
}

void MenuState::Render(SDL_Surface* screen){
    assert(screen);
    
    for (int i = 0; i < m_stateEntities.size(); i++) {
        Drawable_Component* drawableComponent = static_cast<Drawable_Component*>(m_stateEntities[i]->GetComponent(ID(COMPONENT_DRAWABLE)));
        Position_Component* positionComponent = static_cast<Position_Component*>(m_stateEntities[i]->GetComponent(ID(COMPONENT_POSITION)));
        if (drawableComponent && positionComponent){
            WindowManager::GetInstance()->Draw(drawableComponent->get_sprite(), positionComponent->get_left(), positionComponent->get_top());
        }
        else{
            
            Log::Debug("GameState",  "Render() failed for entity " + Numerical_Utilities::num_to_string(m_stateEntities[i]->GetId().GetId()))  ;
        }
        
    }
    
    SDL_Flip(screen);
}

void MenuState::RegisterEntity(Entity* newEntity){
    m_stateEntities.push_back(newEntity);
}

void MenuState::CreateSystems(){
    Log::Info("Menu State", "Create Systems");
}

void MenuState::CreateEntities(){
    
    Entity* backgroundEntity = new Entity( new ID(GameManager::GetNextId()), PROJECTILE_TYPE);
    backgroundEntity->AddComponent(new Drawable_Component(ResourceManager::GetInstance()->GetSprite(MENU_SPRITE)));
    backgroundEntity->AddComponent(new Position_Component(0,0,630,540));
    RegisterEntity(backgroundEntity);
    
    
}

