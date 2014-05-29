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

/** Default Constructor 
 *  Initializes member variables, and constructs path variables.
 *  Process configuration file
 */
n8::Game::Game(const char* configFile){
    Log::Info(TAG, "Constructor");
    
    m_serviceManager = nullptr;
    m_windowWidth = 1;
    m_windowHeight = 1;
    m_fps = DEFAULT_FPS;
    m_quit = false;
    
    //m_configPath = configFile;
    
    InitializeDirectoryPath();
    ProcessConfigFile();
    InitializeResourcesPath();
}

/** Destructor */
n8::Game::~Game(){
    Log::Info(TAG, "Destructor");
}

/** ProcessConfigFile
 *  NOT CURRENTLY IMPLEMENTED
 *  Reads and processes the configuration file
 *  Needed information is saved to member variables so they can be used later
 */
 void n8::Game::ProcessConfigFile(){
     // nothing currently implemented
 }

/** Shutdown
 *  Stops all SDL subsystems
 */
void n8::Game::Shutdown(){
    
    Mix_Quit();
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}

/** Init
 *  Initializes SDL and SDL subsystems for images, sound, font
 */
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

/** Gets and stores the path for the working project directory
 */
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

/** Creates and stores the path for resources directory
 *  WILL CHANGE WHEN DIRECTORY HEIRARCHY IS IMPLEMENTED
 */
void n8::Game::InitializeResourcesPath(){
    m_resourcesListPath = m_directoryPath + RESOURCE_FILE_SUFFIX;
    Log::Debug(TAG, "Resource list file path:" + m_resourcesListPath);
}

/** Setup
 *  Initializes default game systems and member variables
 */
void n8::Game::Setup(){
    Log::Create();
    
    m_serviceManager = ServiceManager::GetInstance();
    
    ResourceManager* resourceManagerService = new ResourceManager(&m_window, m_resourcesListPath.c_str());
    
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
        /*
        frames++;
        curtime = m_timer.GetTime();
        if (curtime-lasttime >= 250) {
            lasttime = curtime;
            std::stringstream ss;
            ss << (frames*4);
            std::string msg("Frames: " + ss.str());
            Log::Info(TAG, msg);
            frames = 0;
        }
         */
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

/** Registers a game state to be used
 *
 *  @param p_key The identifier for the state
 *  @param p_newState A pointer to the state object to be registered for future use
 *
 */
void n8::Game::RegisterState(EState::Values p_key, n8::State* p_newState){
    static_cast<n8::StateManagerService*>(m_serviceManager->GetService(EService::StateManager))->RegisterState(p_key, p_newState);
    
}

/** Clears all states from the stack, and pushes a specified state onto the state stack
 *
 *  @param p_key The identifier for the state to be pushed onto the stack
 */
void n8::Game::SetStartState(EState::Values p_key){
    StateManagerService* stateManager = static_cast<n8::StateManagerService*>(m_serviceManager->GetService(EService::StateManager));
    stateManager->Clear();
    stateManager->PushState(p_key);
    //static_cast<n8::StateManagerService*>(m_serviceManager->GetService(EService::StateManager))->PushState(key);
    
}