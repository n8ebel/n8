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

#include "Singleton.h"
#include "Object.h"


class GameManager : public Singleton<GameManager>,Object{

public:
    static const int DEFAULT_SCREEN_WIDTH = 400;
    static const int DEFAULT_SCREEN_HEIGHT = 400;
    static const int DEFAULT_FPS = 60;
    static const int DEFAULT_BPP= 32;
    
     GameManager();
    ~GameManager();
    
    void RunGame();
    void EndGame();
    
    static int GetNextId();
    
    int SetFPS(int newFPS);
    
    void SetCaption(char* caption);
    void ResizeScreenSurface(int w, int h, int bpp);
    SDL_Surface* GetScreenSurface();
    
protected:
    
    
    
private:
    int m_fps;  /** < value to control game loop speed **/
    Uint32 m_currentTime;  /** < current game time **/
    bool m_quit;  /** < flag to control when game loop ends **/
    
    int m_screenWidth;  /** < width of the screen surface **/
    int m_screenHeight; /** < height of the screen surface **/
    SDL_Surface* m_background;  /** < surface to render things to **/
    
    static int m_nextId; /** < Static counter to get available id values for created entities **/
    
    
    
    
};



#endif
