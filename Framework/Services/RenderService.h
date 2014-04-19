/*
 *  RenderService.h
 *  goobar
 *
 *  Created by Nate Ebel on 4/18/14.
 *  Copyright (c) 2014 n8Tech. All rights reserved.
 */

#ifndef RENDER_SERVICE
#define RENDER_SERVICE

#include <iostream>
#include <assert.h>

#include "Service.h"
#include "Window.h"
#include "Sprite.h"
#include "Texture.h"

namespace n8 {
    /** \class RenderService
     *  \brief Handles game rendering
     *
     *  This class handles rendering of game images by providing
     *   rendering methods for both sprites and texture.
     */
    class RenderService : public Service{
    public:
        enum ERenderMode{ESprite,ETexture};
        
        RenderService(Window*);
        ~RenderService();
        
        void SetRenderMode(ERenderMode);
        
        void OnNotify(Event*);
        
        void Draw(Sprite*, int, int);
        
        //renders texture at position with default size
        void Draw(Texture* p_texture, int p_x, int p_y);
        //renders texture over a specified area
        void Draw(Texture*, int p_x, int p_y, int p_w, int p_h);
        
        void SetDrawingColor(int p_r, int p_g, int p_b, int p_a);
        
        void ColorBackground();
        void PostToScreen();
        
    private:
        
        Window* m_gameWindow; /**< Pointer to the game window object **/
        ERenderMode m_renderMode;
        
        int m_red;
        int m_green;
        int m_blue;
        int m_alpha;
        
    };
}

#endif /* defined(RENDER_SERVICE) */
