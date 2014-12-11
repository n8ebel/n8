/*
 * ImageView.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            11/19/14
 * Organization:    n8
 *
 */

#ifndef N8_GUI_IMAGEVIEW
#define N8_GUI_IMAGEVIEW

#include <stdio.h>
#include <string>

#include "GUIElement.h"
#include "Texture.h"

namespace gui{
    
class ImageView : public GUIElement{
public:
    ImageView(std::shared_ptr<n8::Window> p_window, std::string, std::shared_ptr<n8::Texture>, int p_x, int p_y, int p_w, int p_h);
    
    ~ImageView();
    
    void Draw(const std::shared_ptr<n8::Window>) const override;
    bool Update(Uint32) override;
    
private:
    std::shared_ptr<n8::Texture> m_texture;
};
    
}

#endif /* defined(N8_GUI_IMAGEVIEW) */
