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

namespace gui{
    
    /** \class Container
     *  \brief GUI element that can hold other elements.
     *
     *  Container allows for gui elements to be stored and drawn within some
     *  background.  Used for thigns like toolbars where the elements should
     *  be drawn relative to the parent object.
     */
    class Container : public GUIElement{
    public:
        Container(std::shared_ptr<n8::Window> p_window,std::string p_id, int p_x, int p_y, int p_w, int p_h);
        virtual ~Container();
        
        void AddElement(std::shared_ptr<GUIElement>);
        
        virtual void Draw(const std::shared_ptr<n8::Window>) const override;
        virtual bool CheckMouseClickDown(int p_x, int p_y) const override;
        virtual bool CheckMouseClickUp(int p_x, int p_y) const override;
        virtual bool CheckMouseMove(int p_x, int p_y) const override;
        
        virtual void SetStyle(Style p_style);
        
        bool Update(Uint32 p_currentTime) override;
    protected:
        
        virtual void OffsetPosition(int p_x, int p_y) override;
        
        std::vector<std::shared_ptr<GUIElement>> m_guiElements; /** < List of elements contained by the container.  All elements will be drawn relative to the container's position */
        
    };
}

#endif /* defined(CONTAINER_H) */
