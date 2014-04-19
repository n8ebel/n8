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
        RenderService(Window*);
        ~RenderService();
        
        void OnNotify(Event*);
        
        void DrawSprite(Sprite*, int, int);
        
    private:
        
        Window* m_gameWindow; /**< Pointer to the game window object **/
        
        
    };
}

#endif /* defined(RENDER_SERVICE) */
