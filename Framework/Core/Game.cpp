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
    
    m_configPath = configFile;
    
    InitializeDirectoryPath();
    ProcessConfigFile();
    InitializeResourcesPath();
}

/** Destructor */
n8::Game::~Game(){
    
}

/** ProcessConfigFile
 *  Reads and processes the configuration file
 *  Needed information is saved to member variables so they can be used later
 */
 void n8::Game::ProcessConfigFile(){
     
}

/** Shutdown
 *  Deletes registers game systems which in turn delete all other game data
 */
void n8::Game::Shutdown(){
    
    Mix_Quit();
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}

void n8::Game::Init(){
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        // Unrecoverable error, exit here.
        Log::Error(TAG, "SDL_Init failed: " + string(SDL_GetError()));
    }
    else{
        Log::Info(TAG, "SDL Initializaed");
        
        //Initialize PNG loading
        int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
        if( !( IMG_Init( imgFlags ) & imgFlags ) )
        {
            std::string msg( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
            Log::Error(TAG, msg);
        }
        else{
            Log::Info(TAG, "SDL_Image Initialized");
        }
        
        //Initialize SDL_mixer
        if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        {
            std::string msg("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
            Log::Error(TAG, msg);
            
        }
        else{
            Log::Info(TAG, "SDL_Mixer Initialized");
        }
        
        //Initialize SDL_ttf
        if( TTF_Init() == -1 )
        {
            std::string msg( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
            Log::Error(TAG, msg);
        }
        else{
            Log::Info(TAG, "SDL_ttf Initialized");
        }
    }
}

void n8::Game::InitializeDirectoryPath() {
    char* base_path = SDL_GetBasePath();
    
    if (base_path) {
        m_directoryPath = SDL_strdup(base_path);
        Log::Debug(TAG, "Project Directory: " + m_directoryPath);
        SDL_free(base_path);
    } else {
        m_directoryPath = SDL_strdup("./");
    }
}

void n8::Game::InitializeResourcesPath(){
    m_resourcesListPath = m_directoryPath + RESOURCE_FILE_SUFFIX;
    Log::Debug(TAG, "Resource list file path:" + m_resourcesListPath);
}

/** Setup
 *  Initializes default game systems and member variables
 */
void n8::Game::Setup(){
    Log::Create();
    
    ResourceManager* resourceManagerService = new ResourceManager(&m_window, m_resourcesListPath.c_str());
    
    m_serviceManager = ServiceManager::GetInstance();
    
    InputService* inputService = new InputService();
    StateManagerService* stateManagerService = new StateManagerService();
   // ResourceManagerService* resourceManagerService = new ResourceManagerService(m_window.GetSurface());
    RenderService* renderService = new RenderService(&m_window);
    AudioService* audioService = new AudioService();
    
    inputService->AddObserver(stateManagerService);
    
    m_serviceManager->RegisterService(EService::Input, inputService);
    m_serviceManager->RegisterService(EService::StateManager, stateManagerService);
    m_serviceManager->RegisterService(EService::Resources, resourceManagerService);
    m_serviceManager->RegisterService(EService::Render, renderService);
    m_serviceManager->RegisterService(EService::Audio, audioService);
    
}

/** Start
 *  Starts the game loop
 */
void n8::Game::Start(){
    
    m_timer.UpdateCurrentTime();
    unsigned lasttime = m_timer.GetTime();
    unsigned curtime = m_timer.GetTime();
    int frames = 0;
    while (m_quit == false) {
        frames++;
        curtime = m_timer.GetTime();
        if (curtime-lasttime >= 1000) {
            lasttime = curtime;
            std::stringstream ss;
            ss << frames;
            std::string msg("Frames: " + ss.str());
            //Log::Info(TAG, msg);
            frames = 0;
        }
        //process input
        static_cast<InputService*>(m_serviceManager->GetService(EService::Input))->HandleInput();
        
        //make sure there is a state on the stack
        if(static_cast<StateManagerService*>(ServiceManager::GetInstance()->GetService(EService::StateManager))->GetStackSize() == 0){
            break;
        }
        
        
        //process state
        static_cast<StateManagerService*>(m_serviceManager->GetService(EService::StateManager))->ProcessState(m_timer.GetTime(), &m_window);
                
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