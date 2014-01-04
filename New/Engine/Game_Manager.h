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

class Game_Manager : public Object{

public:
    static const int DEFAULT_SCREEN_WIDTH = 400;
    static const int DEFAULT_SCREEN_HEIGHT = 400;
    static const int DEFAULT_FPS = 60;
    static const int DEFAULT_BPP= 32;
    
    static Game_Manager* get_instance();
    ~Game_Manager();
    
    void run_game();
    void end_game();
    
    static int get_next_id();
    
    int set_fps(int newFPS);
    
    void set_caption(char* caption);
    void resize_screen_surface(int w, int h, int bpp);
    SDL_Surface* get_screen_surface();
    
protected:
    
    
    
private:
    static Game_Manager* instance_;
    Game_Manager();
    
    int fps_;  /** < value to control game loop speed **/
    Uint32 currentTime_;  /** < current game time **/
    bool quit_;  /** < flag to control when game loop ends **/
    
    int screenWidth_;  /** < width of the screen surface **/
    int screenHeight_; /** < height of the screen surface **/
    SDL_Surface* background_;  /** < surface to render things to **/
    
    static int nextid_; /** < Static counter to get available id values for created entities **/
    
    
    
    
};



#endif
