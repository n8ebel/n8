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
    
    m_inputService = static_cast<n8::InputService*>(n8::ServiceManager::GetInstance()->GetService(EService::Input));
    m_renderService = static_cast<n8::RenderService*>(n8::ServiceManager::GetInstance()->GetService(EService::Render));
    m_audioService = static_cast<n8::AudioService*>(n8::ServiceManager::GetInstance()->GetService(EService::Audio));
                                                    
    CreateSystems();
    CreateEntities();
    
    //build user interface
    m_button1 = new gui::Button("button1", 25,5,100,20, NULL);
    m_button2 = new gui::Button("button2", 275,5,100,20, NULL);
    
    m_toolbar = new gui::Container(0,0,400,30);
    m_toolbar->AddElement(m_button1);
    m_toolbar->AddElement(m_button2);
    
    m_gui.AddElement(m_toolbar);
}

TestState::~TestState(){
    if(m_button1){
        delete m_button1;
    }
    if(m_button2){
        delete m_button2;
    }
}



void TestState::OnResume(){

    //register input commands
    m_inputService->RegisterKeyDownCommand(SDLK_SPACE, new n8::PushStateCommand(EState::Test2));
    m_inputService->RegisterKeyDownCommand(SDLK_ESCAPE, new n8::PopStateCommand());
    
    std::vector<n8::PositionCommand*> commands;
    commands.push_back(new n8::ClickDownGUICommand(&m_gui));
    m_inputService->RegisterMouseButtonDownCommand(new n8::MouseClickCommand(commands));
    m_inputService->RegisterMouseButtonUpCommand(new n8::ClickUpGUICommand(&m_gui));
    m_inputService->RegisterMouseMoveCommand(new n8::MouseMoveCommand(&m_gui));
    

    
//start music
    //m_audioService->PlayMusic(static_cast<n8::Music*>(static_cast<n8::ResourceManager*>(n8::ServiceManager::GetInstance()->GetService(EService::Resources))->GetResource("beat")));
}

void TestState::OnPause(){
    m_inputService->UnregisterKeyCommands();
    m_inputService->UnregisterMouseButtonDownCommand();
    m_inputService->UnregisterMouseMoveCommand();
    
    m_audioService->StopMusic();
}

void TestState::Update(Uint32 currentTime){
    
}

void TestState::Render(n8::Window* p_window){
    m_renderService->SetDrawingColor(255, 0, 0, 255);  //set background color
    
    
    m_renderService->ColorBackground();  //color the background
    
    m_gui.Draw(p_window);
    
    m_renderService->PostToScreen();  //draw everything to the screen
}

void TestState::RegisterEntity(Entity* newEntity){
    //m_stateEntities.push_back(newEntity);
}

void TestState::CreateSystems(){
    
}

void TestState::CreateEntities(){
    
}
