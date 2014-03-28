/*
*  Game.cpp
*  goobar
*
*  Created by Nate Ebel on 3/18/14.
*  Copyright (c) 2014 n8Tech. All rights reserved.
*/

#include <assert.h>

#include "Game.h"

#define TAG "Game"

/** Default Constructor */
n8::Game::Game(const char* configFile){
    Log::Info(TAG, "Constructor");
    
    m_serviceManager = NULL;
    m_windowWidth = 1;
    m_windowHeight = 1;
    m_fps = DEFAULT_FPS;
    m_quit = false;
    
    m_configFilePath = configFile;
    
    InitializeDirectoryPath();
    ProcessConfigFile();
}

/** Destructor */
n8::Game::~Game(){
    
}

/** ProcessConfigFile
 *  Reads and processes the configuration file
 *  Needed information is saved to member variables so they can be used later
 */
 void n8::Game::ProcessConfigFile(){
    tinyxml2::XMLDocument configFile;
    configFile.LoadFile( m_configFilePath);
     
     /*
      tinyxml2::XMLElement* configElement = doc.FirstChildElement( "Config" );
      
      tinyxml2::XMLElement* resourcesElement = configElement->FirstChildElement( "Resources" );
      // Get Images
      tinyxml2::XMLElement* imagesElement = resourcesElement->FirstChildElement("ImageResources");
      const char* imagesPath = imagesElement->GetText();
      printf( "Image Resources Path: %s\n", imagesPath );
      
      // Get Textures
      tinyxml2::XMLElement* texturesElement = resourcesElement->FirstChildElement("TextureResources");
      const char* texturesPath = texturesElement->GetText();
      printf( "Textures Resources Path: %s\n", texturesPath );
      
      // Get Audio
      tinyxml2::XMLElement* audioElement = resourcesElement->FirstChildElement("AudioResources");
      const char* audioPath = audioElement->GetText();
      printf( "Audio Resources Path: %s\n", audioPath );

      */
}

/** Shutdown
 *  Deletes registers game systems which in turn delete all other game data
 */
void n8::Game::Shutdown(){
    
    
    SDL_Quit();
}

void n8::Game::Init(){
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        // Unrecoverable error, exit here.
        Log::Error(TAG, "SDL_Init failed: " + string(SDL_GetError()));
    }
    else{
        Log::Info(TAG, "SDL Initializaed");
    }
}

void n8::Game::InitializeDirectoryPath() {
    char* base_path = SDL_GetBasePath();
    
    if (base_path) {
        m_directoryPath = SDL_strdup(base_path);
        SDL_free(base_path);
    } else {
        m_directoryPath = SDL_strdup("./");
    }
}

/** Setup
 *  Initializes default game systems and member variables
 */
void n8::Game::Setup(std::string configFilePath){
    Log::Create();
    InitializeDirectoryPath();
    
    ResourceManager tmp(m_window.GetSurface(),m_directoryPath);
    
    m_serviceManager = ServiceManager::GetInstance();
    
    InputService* inputService = new InputService();
    StateManagerService* stateManagerService = new StateManagerService();
    ResourceManagerService* resourceManagerService = new ResourceManagerService(m_window.GetSurface());
    
    inputService->AddObserver(stateManagerService);
    
    m_serviceManager->RegisterService(EService::Input, inputService);
    m_serviceManager->RegisterService(EService::StateManager, stateManagerService);
    m_serviceManager->RegisterService(EService::Resources, resourceManagerService);
    
}

/** Start
 *  Starts the game loop
 */
void n8::Game::Start(){
   
    m_timer.UpdateCurrentTime();
    while (m_quit == false) {
        
        //process input
        static_cast<InputService*>(m_serviceManager->GetService(EService::Input))->HandleInput();
        
        //make sure there is a state on the stack
        if(static_cast<StateManagerService*>(ServiceManager::GetInstance()->GetService(EService::StateManager))->GetStackSize() == 0){
            break;
        }
        
        //process state
        static_cast<StateManagerService*>(m_serviceManager->GetService(EService::StateManager))->ProcessState(m_timer.GetTime(), m_window.GetWindow());
        
        
        m_timer.SyncGame(m_fps);  //ensures proper fps
        
    }
}


/** Stop
 *  Stops the running game loop
 */
void n8::Game::Stop(){
    m_serviceManager->RemoveAllServices();
    
    ServiceManager::Destroy();
    
    Log::Destroy();
}

/** Changes the frame per second value for the game loop
 *
 *  @param newFPS The integer value for the fps value
 *
 *  @return The fps value
 */
void n8::Game::SetFPS(unsigned newFPS){
    m_fps = newFPS;
}

/** ResizeWindow
*   Changes the dimensions of the game window
*
*   @param unsigned width The desired width of the window
*   @param unsigned height The desired height of the window
*/
void n8::Game::DefineWindowSize(unsigned width, unsigned height){
    m_windowWidth = width;
    m_windowHeight = height;
    
    assert(&m_window);
    m_window.ResizeWindow(m_windowWidth,m_windowHeight);
}

void n8::Game::RegisterState(EState::Values key, n8::State* newState){
    static_cast<n8::StateManagerService*>(m_serviceManager->GetService(EService::StateManager))->RegisterState(key,newState);
    
}

void n8::Game::SetStartState(EState::Values key){
    static_cast<n8::StateManagerService*>(m_serviceManager->GetService(EService::StateManager))->PushState(key);
    
}