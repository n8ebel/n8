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

TestState::TestState() : m_exitEvent(EEvents::Test2){
    //m_id = new ID(GAME_STATE);
    m_inputService = static_cast<n8::InputService*>(n8::ServiceManager::GetInstance()->GetService(EService::Input));
                                                    
    CreateSystems();
    CreateEntities();
}

TestState::~TestState(){
    
}



void TestState::OnResume(){
    m_inputService->RegisterKeyDownCommand(SDLK_SPACE, new n8::PushStateCommand(EState::Test2));
    m_inputService->RegisterKeyDownCommand(SDLK_ESCAPE, new n8::PopStateCommand());
    
    
}

void TestState::OnPause(){
    m_inputService->UnregisterKeyCommands();
    
}

void TestState::Update(Uint32 currentTime){
    /*
    cout << "updating" << endl;
    if (m_inputService->KeyIsDown(SDLK_SPACE)) {
        static_cast<n8::StateManagerService*>(n8::ServiceManager::GetInstance()->GetService(EService::StateManager))->Notify(&m_exitEvent);
    }
   */
}
void TestState::Render(n8::Window* p_window){
   // assert(screen);
    
    SDL_FillRect(SDL_GetWindowSurface(p_window->GetWindow()), NULL, SDL_MapRGB(SDL_GetWindowSurface(p_window->GetWindow())->format, 200,0,0));
   /*
    static_cast<n8::Sprite*>(static_cast<n8::ResourceManager*>(n8::ServiceManager::GetInstance()->GetService(EService::Resources))->GetResource("menu.png"))->Draw(20,20,SDL_GetWindowSurface(p_window));
    */
    //Update the surface
    SDL_UpdateWindowSurface( p_window->GetWindow() );
    
}

void TestState::RegisterEntity(Entity* newEntity){
    //m_stateEntities.push_back(newEntity);
}

void TestState::CreateSystems(){
    //SystemManager::GetInstance()->RegisterSystem(RENDER_SYSTEM, new RenderSystem());
}

void TestState::CreateEntities(){
    

}
