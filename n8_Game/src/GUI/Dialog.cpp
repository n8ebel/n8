//
//  Dialog.cpp
//  n8_Game
//
//  Created by Nate Ebel on 10/24/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#include "Dialog.h"

namespace gui {
    int gui::Dialog::DEFAULT_WIDTH = 300;
    
    int gui::Dialog::DEFAULT_HEIGHT = 250;
    
    int gui::Dialog::DEFAULT_TITLE_HEIGHT = 24;
    
    Dialog::Builder::Builder(n8::Window* pWindow){
        m_window = pWindow;
        int x = pWindow->GetWidth()/2 - DEFAULT_WIDTH/2;
        int y = pWindow->GetHeight()/2 - DEFAULT_HEIGHT/2;
        mDialog = new Dialog(m_window, x, y, DEFAULT_WIDTH, DEFAULT_HEIGHT);
    }
    
    Dialog* Dialog::Builder::Create(){
        mDialog->Build(m_window);
        return mDialog;
    }
    
    Dialog::Builder* Dialog::Builder::SetWidth(int width){
        mDialog->SetWidth(width);
        return this;
    }
    
    Dialog::Builder* Dialog::Builder::SetHeight(int height){
        mDialog->SetHeight(height);
        return this;
    }
    
    Dialog::Builder* Dialog::Builder::SetTitle(std::string pString){
        mDialog->mTitle = pString;
        return this;
    }
    
    Dialog::Builder* Dialog::Builder::SetPositiveButton(std::string text, std::function<void()> function){
        mDialog->mPositiveButton = new Button(m_window, "positive", text, 0, 0,80,30);
        mDialog->mPositiveButton->setClickHandler(function);
        return this;
    }
    
    Dialog::Builder* Dialog::Builder::SetNegativeButton(std::string text, std::function<void()> function){
        mDialog->mNegativeButton = new Button(m_window, "negative", text, 0, 0,80,30);
        mDialog->mNegativeButton->setClickHandler(function);
        return this;
    }
    
    Dialog::Builder* Dialog::Builder::SetNeutralButton(std::string text, std::function<void()> function){
        mDialog->mNeutralButton = new Button(m_window, "neutral", text, 0, 0,80,30);
        mDialog->mNeutralButton->setClickHandler(function);
        return this;
    }
    
    Dialog::Builder* Dialog::Builder::SetOnDismissedListener(std::function<void()> function){
        mDialog->SetOnDismissedListener(function);
        return this;
    }
    
    
    gui::Dialog::Dialog(n8::Window* p_window, int p_x, int p_y, int p_w, int p_h ) : Container(p_window, "",p_x,p_y,p_w,p_h)
    {
        mTitle = "";
        mDismissedListener = nullptr;
        mPositiveButton = nullptr;
        mNegativeButton = nullptr;
        mNeutralButton = nullptr;
    }
    
    gui::Dialog::~Dialog(){
        Container::~Container();
        m_function = nullptr;
        if (mPositiveButton) {
            delete mPositiveButton;
        }
        if (mNegativeButton) {
            delete mNegativeButton;
        }
        if (mNeutralButton) {
            delete mNeutralButton;
        }
    }
    
    /** Builds the button.
     * Loads the rendered text texture using the game window pointer from
     *  style pointer.
     */
    void gui::Dialog::Build(n8::Window* window){
        Container::Build(window);
        
        std::cout << m_style.GetFontPath() << std::endl;
        TTF_Font* font = TTF_OpenFont(m_style.GetFontPath().c_str(), DEFAULT_TITLE_HEIGHT);
        
        m_built = mTitleTextTexture.loadFromRenderedText(  window->GetRenderer(), font, mTitle.c_str(), m_style.GetColor(Style::EStyleColor::Font).GetColor() );
        
        TTF_CloseFont(font);
        
        
        if (mPositiveButton && mNegativeButton && mNeutralButton) {
            mPositiveButton->SetPosition(10, m_h - 40);
            mNegativeButton->SetPosition(m_w-90, m_h - 40);
            mNeutralButton->SetPosition(m_w/2-40, m_h - 40);
        }
        else if (mPositiveButton && mNegativeButton) {
            mPositiveButton->SetPosition((m_x+m_w)/2-80/2-10, m_h-40);
            mNegativeButton->SetPosition((m_x+m_w)/2 + 10, m_h-40);
        }
        else if(mPositiveButton && mNeutralButton){
            mPositiveButton->SetPosition((m_x+m_w)/2-80/2-10, m_h-40);
            mNeutralButton->SetPosition((m_x+m_w)/2 + 10, m_h-40);
        }
        else if(mNegativeButton && mNeutralButton){
            mNegativeButton->SetPosition((m_x+m_w)/2-80/2-10, m_h-40);
            mNeutralButton->SetPosition((m_x+m_w)/2 + 10, m_h-40);
        }
        else if(mPositiveButton){
            mPositiveButton->SetPosition( (m_x+m_w)/2 - 80/2, m_h-40);
        }
        else if(mNegativeButton){
            mNegativeButton->SetPosition( (m_x+m_w)/2 - 80/2, m_h-40);
        }
        else if(mNeutralButton){
            mNeutralButton->SetPosition( (m_x+m_w)/2 - 80/2, m_h-40);
        }
        
        AddElement(mPositiveButton);
        AddElement(mNegativeButton);
        AddElement(mNeutralButton);
        
        if (mPositiveButton) {
            mPositiveButton->SetStyle(m_style);
            mPositiveButton->Build(window);
        }
        if (mNegativeButton) {
            mNegativeButton->SetStyle(m_style);
            mNegativeButton->Build(window);
        }
        if (mNeutralButton) {
            mNeutralButton->SetStyle(m_style);
            mNeutralButton->Build(window);
        }
        
    }
    
    bool gui::Dialog::CheckMouseClickDown(int pX, int pY){
        Container::CheckMouseClickDown(pX, pY);
        return positionWithinElement(pX, pY);
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
        
        // Set draw color for dialog outline
        drawColor = m_style.GetColor(Style::EStyleColor::Focus);
        SDL_SetRenderDrawColor( renderer,
                               drawColor.GetR(),
                               drawColor.GetG(),
                               drawColor.GetB(),
                               drawColor.GetA()
                               );
        
        SDL_RenderDrawRect(renderer, m_rectangle.GetRect());
        
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