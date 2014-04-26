/*
 * Container.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            4/20/14
 * Organization:    n8Tech
 *
 */

#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
#include <vector>

#include "GUIElement.h"
#include "Widget.h"



namespace gui{
    class Container : public GUIElement{
    public:
        Container(int p_x, int p_y, int p_w, int p_h);
        virtual ~Container();
        
        virtual void Draw(n8::Window*) override;
        virtual bool CheckMouseClickDown(int p_x, int p_y) override;
        virtual bool CheckMouseClickUp(int p_x, int p_y) override;
        virtual bool CheckMouseMove() override;
        
        bool Update(Uint32 p_currentTime) override;
        void AddElement(GUIElement*);
        
    protected:
        std::vector<GUIElement*> m_guiElements;
        
    };
}

#endif /* defined(CONTAINER_H) */
