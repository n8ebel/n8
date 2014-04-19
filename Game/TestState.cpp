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
    m_renderService = static_cast<n8::RenderService*>(n8::ServiceManager::GetInstance()->GetService(EService::Render));
    m_audioService = static_cast<n8::AudioService*>(n8::ServiceManager::GetInstance()->GetService(EService::Audio));
                                                    
    CreateSystems();
    CreateEntities();
}

TestState::~TestState(){
    
}



void TestState::OnResume(){
    m_inputService->RegisterKeyDownCommand(SDLK_SPACE, new n8::PushStateCommand(EState::Test2));
    m_inputService->RegisterKeyDownCommand(SDLK_ESCAPE, new n8::PopStateCommand());
    
    m_audioService->PlayMusic(static_cast<n8::Music*>(static_cast<n8::ResourceManager*>(n8::ServiceManager::GetInstance()->GetService(EService::Resources))->GetResource("beat")));
    
}

void TestState::OnPause(){
    m_inputService->UnregisterKeyCommands();
    
    m_audioService->StopMusic();
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
   m_renderService->SetDrawingColor(255, 0, 0, 255);
    
    //texture rendering
    m_renderService->ColorBackground();
    
    m_renderService->Draw(static_cast<n8::Texture*>(static_cast<n8::ResourceManager*>(n8::ServiceManager::GetInstance()->GetService(EService::Resources))->GetResource("sayainTexture")),10,10);
    
    m_renderService->Draw(static_cast<n8::Texture*>(static_cast<n8::ResourceManager*>(n8::ServiceManager::GetInstance()->GetService(EService::Resources))->GetResource("sayainTexture")),10,80,100,100);
    
    m_renderService->PostToScreen();
    
}

void TestState::RegisterEntity(Entity* newEntity){
    //m_stateEntities.push_back(newEntity);
}

void TestState::CreateSystems(){
    
}

void TestState::CreateEntities(){
    
}
