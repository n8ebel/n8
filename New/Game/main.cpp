//
//  main.cpp
//  goobar
//
//  Created by Nate Ebel on 12/22/13.
//  Copyright (c) 2013 n8Tech. All rights reserved.
//


#include "n8.h"

#include "GameState.h"
#include "MenuState.h"

#include "Values.h"

#include <iostream>

using namespace std;



int main(int argc, char* argv[]){
    //SDL_Init( SDL_INIT_EVERYTHING );
    
    Log::TurnOnDebuggingMessages();
    Log::TurnOnInfoMessages();
    Log::TurnOnErrorMessages();
    
    if(n8::Setup()){
    
        
    
        WindowManager::GetInstance()->SetCaption("n8");
        WindowManager::GetInstance()->ResizeScreenSurface(630, 540, WindowManager::DEFAULT_BPP);
        
        StateManager::GetInstance()->RegisterState(GAME_STATE, new GameState());
        StateManager::GetInstance()->RegisterState(MENU_STATE, new MenuState());
        
        StateManager::GetInstance()->PushState(GAME_STATE);
    
        
        GameManager::GetInstance()->RunGame();
        
        n8::Shutdown();
         
    }
    
    
    
    
    SDL_Quit();
    return 0;
}
