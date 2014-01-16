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
    static const int DEFAULT_FPS = 60;
    
    GameManager();
    ~GameManager();
    
    void RunGame();
    void EndGame();
    
    static int GetNextId();
    
    int SetFPS(int newFPS);
    
protected:
    
    
    
private:
    int m_fps;  /** < value to control game loop speed **/
    Uint32 m_currentTime;  /** < current game time **/
    bool m_quit;  /** < flag to control when game loop ends **/
    
    static int m_nextId; /** < Static counter to get available id values for created entities **/
    
    
    
    
};



#endif
