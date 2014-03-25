/*
 * WindowManager.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            1/15/14
 * Organization:    n8Tech
 *
 */

#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include "Sprite.h"
#include "Singleton.h"
#include "Object.h"

#include <vector>



class WindowManager : public Singleton<WindowManager>,Object{
    
public:
    static const int DEFAULT_SCREEN_WIDTH = 400;
    static const int DEFAULT_SCREEN_HEIGHT = 400;
    static const int DEFAULT_BPP= 32;
    
    WindowManager();
    ~WindowManager();
    
    void SetCaption(char* caption);
    void ResizeScreenSurface(int w, int h, int bpp);
    SDL_Surface* GetScreenSurface();
    
    void Draw(Sprite*, int, int);
    //void Draw(Sprite*, int, int, Camera*);
    
protected:
    
    
    
private:
    
    int m_screenWidth;  /** < width of the screen surface **/
    int m_screenHeight; /** < height of the screen surface **/
    SDL_Surface* m_background;  /** < surface to render things to **/
    
};

#endif