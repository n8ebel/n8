//
//  Dialog.cpp
//  n8_Game
//
//  Created by Nate Ebel on 10/24/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#include "Dialog.h"

namespace gui {
    gui::Dialog::Dialog( std::string p_id,std::string p_text, int p_x, int p_y, int p_w, int p_h ) : Container(p_id,p_x,p_y,p_w,p_h)
    {
        mTitle = p_text;
        mDismissedListener = nullptr;
        
        AddElement(new Button("a", "OK", 10,10,50,15));
    }
    
    gui::Dialog::~Dialog(){
        if (m_texture) {
            SDL_DestroyTexture(m_texture);
            m_texture = nullptr;
        }
        m_function = nullptr;
    }
    
    /** Builds the button.
     * Loads the rendered text texture using the game window pointer from
     *  style pointer.
     */
    void gui::Dialog::Build(n8::Window* window){
        
        
        m_built = mTitleTextTexture.loadFromRenderedText(  window->GetRenderer(), m_style.GetFont()->GetFont(), mTitle.c_str(), m_style.GetColor(Style::EStyleColor::Font).GetColor() );
        
        GUIElement::Build(window);
        
    }
    
    bool gui::Dialog::CheckMouseClickDown(int pX, int py){
        
        return Container::CheckMouseClickDown(pX, py);
    }
    
    bool gui::Dialog::CheckMouseClickUp(int pX, int pY){
        
        Container::CheckMouseClickUp(pX, pY);
        
        return positionWithinElement(pX, pY);
    }
    
    bool gui::Dialog::CheckMouseMove(int pX, int py){
        
        return Container::CheckMouseMove(pX, py);
    }
    
    bool gui::Dialog::Update(Uint32 p_currentTime){
        return true;
    }
    
    void gui::Dialog::Draw(n8::Window* pWindow){
        
        Container::Draw(pWindow);
        
        // Set draw color for text
        SDL_Renderer* renderer = pWindow->GetRenderer();
        n8::Color drawColor = m_style.GetColor(Style::EStyleColor::Font);
        SDL_SetRenderDrawColor( renderer,
                               drawColor.GetR(),
                               drawColor.GetG(),
                               drawColor.GetB(),
                               drawColor.GetA()
                               );
        
        if(mTitleTextTexture.HasTexture()){
            int x = m_x + (m_w - mTitleTextTexture.getWidth())/2;
            int y = m_y + 10;
            mTitleTextTexture.render(renderer, x,y);
        }
    }
    
    void gui::Dialog::SetOnDismissedListener(std::function<void()> function){
        mDismissedListener = function;
    }
    
    void gui::Dialog::Dismiss(){
        if (mDismissedListener != nullptr) {
            mDismissedListener();
        }
    }
    
}