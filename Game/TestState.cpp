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

TestState::TestState() : m_gui(nullptr),m_exitEvent(EEvents::Test2){
    
    m_inputService = static_cast<n8::InputService*>(n8::ServiceManager::GetInstance()->GetService(EService::Input));
    m_renderService = static_cast<n8::RenderService*>(n8::ServiceManager::GetInstance()->GetService(EService::Render));
    m_audioService = static_cast<n8::AudioService*>(n8::ServiceManager::GetInstance()->GetService(EService::Audio));
    
    CreateSystems();
    CreateEntities();
    
    
    //build user interface
    m_font = (n8::Font*)((n8::ResourceManager*)n8::ServiceManager::GetInstance()->GetService(EService::Resources))->GetResource("stocky24");
    
    m_gui = new gui::GUI(const_cast<n8::Window*>(m_renderService->GetWindow()),m_font);
    m_gui->GetStyle().GetWindow()->GetWindow();
    m_button1 = new gui::Button("button1", 25,5,100,20, NULL);
    m_button2 = new gui::Button("button2", 275,5,100,20, NULL);
    m_inputBox = new gui::InputBox(50,300,300,50, "Enter Text");
    
    m_toolbar = new gui::Container(0,0,400,30);
    m_toolbar->AddElement(m_button1);
    m_toolbar->AddElement(m_button2);
    
    m_label = new gui::Label("hi there", 100,100);
    
    m_gui->AddElement(m_toolbar);
    m_gui->AddElement(m_inputBox);
    m_gui->AddElement(m_label);
    
    m_gui->Build();
    
    m_inputService->RegisterUserInterface(m_gui);
    
    
     
}

TestState::~TestState(){
    if (m_gui) {
       delete m_gui;
       m_gui = nullptr;
    }/*
    if(m_button1){
        delete m_button1;
        m_button1 = nullptr;
    }
    if(m_button2){
        delete m_button2;
        m_button2 = nullptr;
    }
    if (m_toolbar) {
        delete m_toolbar;
        m_toolbar = nullptr;
    }
    if(m_inputBox){
        delete m_inputBox;
        m_inputBox = nullptr;
    }
    if (m_label) {
        delete m_label;
        m_label = nullptr;
    }
      */
}



void TestState::OnResume(){
    
    //register keyboard commands
    m_inputService->RegisterKeyDownCommand(SDLK_SPACE, new n8::PushStateCommand(EState::Test2));
    m_inputService->RegisterKeyDownCommand(SDLK_ESCAPE, new n8::PopStateCommand());
    
    //register mouse actions
    m_inputService->RegisterMouseMoveAction( [this](){
        if (m_gui) {
             m_gui->CheckMove();
        }
    });
    
    m_inputService->RegisterMouseButtonUpAction( [this](int x, int y){
        if (m_gui) {
            m_gui->CheckClickUp(x, y);
        }
    });
    
    m_inputService->RegisterMouseButtonDownAction( [this](int x, int y){
        if (m_gui) {
            m_gui->CheckClickDown(x, y);
        }
    });
    
//start music
    //m_audioService->PlayMusic(static_cast<n8::Music*>(static_cast<n8::ResourceManager*>(n8::ServiceManager::GetInstance()->GetService(EService::Resources))->GetResource("beat")));
}

void TestState::OnPause(){
    m_inputService->UnregisterKeyCommands();
    m_inputService->UnregisterMouseButtonDownAction();
    m_inputService->UnregisterMouseButtonUpAction();
    m_inputService->UnregisterMouseMoveAction();
    
    m_audioService->StopMusic();
}

void TestState::Update(Uint32 currentTime){
    if (m_gui){
        m_gui->Update(currentTime);
    }
}

void TestState::Render(n8::Window* p_window){
    m_renderService->SetDrawingColor(255, 0, 0, 255);  //set background color
    
    
    m_renderService->ColorBackground();  //color the background
    
    if (m_gui) {
         m_gui->Draw(p_window);
    }
   
    //m_renderService->DrawText("goobaroo", m_font, n8::RenderService::EColor::Black, 100, 250);
    
    m_renderService->PostToScreen();  //draw everything to the screen
                                              
}

void TestState::RegisterEntity(Entity* newEntity){
    //m_stateEntities.push_back(newEntity);
}

void TestState::CreateSystems(){
    
}

void TestState::CreateEntities(){
    
}
