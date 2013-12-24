/*
 * GameManager.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            12/22/13
 * Organization:    n8Tech
 *
 */

#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "Object.h"
#include "State_Manager.h"
#include "State.h"


class GameManager :public Object{

public:
    static const int DEFAULT_SCREEN_WIDTH = 400;
    static const int DEFAULT_SCREEN_HEIGHT = 400;
    static const int DEFAULT_FPS = 60;
    static const int DEFAULT_BPP= 32;
    
    static GameManager* getGameManager();
    ~GameManager();
    
    void startGame();
    void endGame();
    
    
    
    int setFPS(int newFPS);
    
    void setCaption(char* caption);
    void resizeScreenSurface(int w, int h, int bpp);
    SDL_Surface* getScreenSurface();
    
protected:
    
    
    
private:
    static GameManager* GameManager_Instance_;
    GameManager();
    
    State_Manager* stateManager_;
    
    
    int fps_;
    Uint32 currentTime_;
    bool quit_;
    
    int screenWidth_;
    int screenHeight_;
    SDL_Surface* background_;
    
    
    
    
};



#endif
