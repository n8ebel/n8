#include <iostream>

#include "Game.h"
#include "TestState.h"
#include "TestState2.h"

int main(int argc, char * arg[])
{
    n8::Game::Init();
    n8::Game game;
    game.Setup();
    
    TestState testState;
    game.RegisterState(EState::Test, &testState);
    
    TestState2 testState2;
    game.RegisterState(EState::Test2, &testState2);
    
    game.SetStartState(EState::Test);
    
    game.Start();
    
    
    
    
    game.Stop();
    game.Shutdown();
    
    
    return 0;
        
}

