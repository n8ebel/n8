/*
*  Game.cpp
*  goobar
*
*  Created by Nate Ebel on 3/18/14.
*  Copyright (c) 2014 n8Tech. All rights reserved.
*/

#include <assert.h>
#include <memory>

#include "Game.h"

#define TAG "Game"

/** Default Constructor 
 *  Initializes member variables, and constructs path variables.
 *  Process configuration file
 */
n8::Game::Game(const char* configFile) : m_serviceManager(){
    Log::Info(TAG, "Constructor");
    
    m_windowWidth = 1;
    m_windowHeight = 1;
    m_fps = DEFAULT_FPS;
    m_quit = false;
    m_showDebugInfo = false;
    
    m_resourceConfigPath = configFile;
    
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        // Unrecoverable error, exit here.
        Log::Error(TAG, "SDL_Init failed: " + string(SDL_GetError()));
        exit(FAILURE_SDL_INIT);
    }
    else{
        Log::Info(TAG, "SDL Initializaed");
        
        //Initialize PNG loading
        int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
        if( !( IMG_Init( imgFlags ) & imgFlags ) )
        {
            std::string msg( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
            Log::Error(TAG, msg);
            exit(FAILURE_SDL_IMG);
        }
        else{
            Log::Info(TAG, "SDL_Image Initialized");
        }
        
        //Initialize SDL_mixer
        if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        {
            std::string msg("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
            Log::Error(TAG, msg);
            exit(FAILURE_SDL_MIX);
            
        }
        else{
            Log::Info(TAG, "SDL_Mixer Initialized");
        }
        
        //Initialize SDL_ttf
        if( TTF_Init() == -1 )
        {
            std::string msg( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
            Log::Error(TAG, msg);
            exit(FAILURE_SDL_TTF);
        }
        else{
            Log::Info(TAG, "SDL_ttf Initialized");
        }
        
        InitializeDirectoryPath();
        ProcessConfigFile();
        InitializeResourcesPath();
        
        Log::GetInstance();
        
        m_window = std::make_shared<n8::Window>();
    }
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
        auto resourceManagerService = std::make_shared<ResourceManager>(shared_from_this(), m_window, m_resourceConfigPath.c_str());
        auto inputService = std::make_shared<InputService>(shared_from_this());
        auto stateManagerService = std::make_shared<StateManagerService>(shared_from_this());
        auto renderService = std::make_shared<RenderService>(shared_from_this(), m_window);
        auto audioService = std::make_shared<AudioService>(shared_from_this());
        
        inputService->AddObserver(stateManagerService.get());
        
        m_serviceManager.RegisterService(ServiceManager::INPUT, inputService);
        m_serviceManager.RegisterService(ServiceManager::STATE_MANAGER, stateManagerService);
        m_serviceManager.RegisterService(ServiceManager::RESOURCES, resourceManagerService);
        m_serviceManager.RegisterService(ServiceManager::RENDER, renderService);
        m_serviceManager.RegisterService(ServiceManager::AUDIO, audioService);
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
    Log::Debug(TAG, "Resource config file path:" + m_resourceConfigPath);
}

/** Start
 *  Starts the game loop
 */
void n8::Game::Start(){
    
    m_timer.UpdateCurrentTime();
    unsigned lasttime = m_timer.GetTime();
    unsigned curtime = m_timer.GetTime();
    int frames = 0;
    
    auto inputService = getInputService();
    auto stateManager = getStateManagerService();
    while (m_quit == false) {
        
        if (m_showDebugInfo) {
            frames++;
            curtime = m_timer.GetTime();
            if (curtime-lasttime >= 250) {
                lasttime = curtime;
                std::stringstream ss;
                ss << (frames*4);
                std::string msg("Frames: " + ss.str());
                std::cout << msg << std::endl;
                frames = 0;
            }
        }
        
        //process input
        inputService->HandleInput();
        
        //make sure there is a state on the stack
        if(stateManager->GetStackSize() == 0){
            break;
        }
        
        
        //process state
        stateManager->ProcessState(m_timer.GetTime(), m_window);
                
        m_timer.SyncGame(m_fps);  //ensures proper fps
        
    }
}


/** Stop
 *  Stops the running game loop
 */
void n8::Game::Stop(){ }

/** Changes the frame per second value for the game loop
 *
 *  @param newFPS The integer value for the fps value
 *
 *  @return The fps value
 */
void n8::Game::SetFPS(Uint8 newFPS){
    m_fps = newFPS;
}

void n8::Game::ShowDebugInfo(bool showDebugInfo){
    m_showDebugInfo = showDebugInfo;
}

/** ResizeWindow
*   Changes the dimensions of the game window
*
*   @param unsigned width The desired width of the window
*   @param unsigned height The desired height of the window
*/
void n8::Game::DefineWindowSize(Uint16 width, Uint16 height){
    m_windowWidth = width;
    m_windowHeight = height;
    
    m_window->ResizeWindow(m_windowWidth,m_windowHeight);
}


void n8::Game::StartState(std::shared_ptr<n8::State> newState){
    getStateManagerService()->PushState(newState);
}

void n8::Game::EndState(){
    getStateManagerService()->PopState();
}

const std::shared_ptr<n8::Window> n8::Game::getWindow() const{
    return m_window;
}

const std::shared_ptr<n8::ResourceManager> n8::Game::getResourceManager() const{
    return std::static_pointer_cast<ResourceManager>(m_serviceManager.GetService(ServiceManager::RESOURCES));
}

const std::shared_ptr<n8::InputService> n8::Game::getInputService() const{
    return std::static_pointer_cast<InputService>(m_serviceManager.GetService(ServiceManager::INPUT));
}

const std::shared_ptr<n8::StateManagerService> n8::Game::getStateManagerService() const{
    return std::static_pointer_cast<StateManagerService>(m_serviceManager.GetService(ServiceManager::STATE_MANAGER));
}

const std::shared_ptr<n8::RenderService> n8::Game::getRenderService() const{
    return std::static_pointer_cast<RenderService>(m_serviceManager.GetService(ServiceManager::RENDER));
}

const std::shared_ptr<n8::AudioService> n8::Game::getAudioService() const{
    return std::static_pointer_cast<AudioService>(m_serviceManager.GetService(ServiceManager::AUDIO));
}
