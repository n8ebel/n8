//
//  Dialog.cpp
//  n8_Game
//
//  Created by Nate Ebel on 10/24/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#include "Dialog.h"

namespace gui {
    
    Dialog::Builder::Builder(n8::Window* pWindow){
        m_window = pWindow;
        int x = pWindow->GetWidth()/2 - Style::DEFAULT_DIALOG_WIDTH/2;
        int y = pWindow->GetHeight()/2 - Style::DEFAULT_DIALOG_HEIGHT/2;
        mDialog = new Dialog(m_window, x, y, Style::DEFAULT_DIALOG_WIDTH, Style::DEFAULT_DIALOG_HEIGHT);
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
        return SetPositiveButton(text, Style::DEFAULT_BUTTON_WIDTH, Style::DEFAULT_BUTTON_HEIGHT, function);
    }
    
    Dialog::Builder* Dialog::Builder::SetPositiveButton(std::string text, int width, int height, std::function<void()> function){
        mDialog->mPositiveButton = new Button(m_window, "positive", text, 0, 0, width, height);
        mDialog->mPositiveButton->SetTextSize(Style::DEFAULT_DIALOG_BUTTON_FONT_SIZE);
        mDialog->mPositiveListener = function;
        mDialog->mPositiveButton->setClickHandler([this](){
            if (mDialog->mPositiveListener) {
                mDialog->mPositiveListener();
            }
            mDialog->mIsOpen = false;
        });
        return this;
    }
    
    Dialog::Builder* Dialog::Builder::SetNegativeButton(std::string text, std::function<void()> function){
        return SetNegativeButton(text, Style::DEFAULT_BUTTON_WIDTH, Style::DEFAULT_BUTTON_HEIGHT, function);
    }
    
    Dialog::Builder* Dialog::Builder::SetNegativeButton(std::string text, int width, int height, std::function<void()> function){
        mDialog->mNegativeButton = new Button(m_window, "negative", text, 0, 0, width, height);
        mDialog->mNegativeButton->SetTextSize(Style::DEFAULT_DIALOG_BUTTON_FONT_SIZE);
        mDialog->mNegativeListener = function;
        mDialog->mNegativeButton->setClickHandler([this](){
            if (mDialog->mNegativeListener) {
                mDialog->mNegativeListener();
            }
            mDialog->mIsOpen = false;
        });
        return this;
    }
    
    Dialog::Builder* Dialog::Builder::SetNeutralButton(std::string text, std::function<void()> function){
        return SetNeutralButton(text, Style::DEFAULT_BUTTON_WIDTH, Style::DEFAULT_BUTTON_HEIGHT, function);
    }
    
    Dialog::Builder* Dialog::Builder::SetNeutralButton(std::string text, int width, int height, std::function<void()> function){
        mDialog->mNeutralButton = new Button(m_window, "neutral", text, 0, 0, width, height);
        mDialog->mNeutralButton->SetTextSize(Style::DEFAULT_DIALOG_BUTTON_FONT_SIZE);
        mDialog->mNeutralListener = function;
        mDialog->mNeutralButton->setClickHandler([this](){
            if (mDialog->mNeutralListener) {
                mDialog->mNeutralListener();
            }
            mDialog->mIsOpen = false;
        });
        return this;
    }
    
    Dialog::Builder* Dialog::Builder::SetOnDismissedListener(std::function<void()> function){
        mDialog->SetOnDismissedListener(function);
        return this;
    }
    
    
    gui::Dialog::Dialog(n8::Window* p_window, int p_x, int p_y, int p_w, int p_h ) : Container(p_window, "",p_x,p_y,p_w,p_h)
    {
        mTitle = "";
        mIsOpen = false;
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
    
    void gui::Dialog::SetIsOpen(){
        mIsOpen = true;
    }
    
    /** Builds the button.
     * Loads the rendered text texture using the game window pointer from
     *  style pointer.
     */
    void gui::Dialog::Build(n8::Window* window){
        
        TTF_Font* font = TTF_OpenFont(m_style.GetFontPath().c_str(), Style::DEFAULT_TITLE_HEIGHT);
        
        m_built = mTitleTextTexture.loadFromRenderedText(  window->GetRenderer(), font, mTitle.c_str(), m_style.GetColor(Style::EStyleColor::Font).GetColor() );
        
        TTF_CloseFont(font);
        
        if (mPositiveButton && mNegativeButton && mNeutralButton) {
            mPositiveButton->SetPosition(Style::DEFAULT_MARGIN, m_h - mPositiveButton->GetHeight());
            mNegativeButton->SetPosition(m_w - mNegativeButton->GetWidth() - Style::DEFAULT_MARGIN, m_h - mNegativeButton->GetHeight());
            mNeutralButton->SetPosition(m_w/2 - mNeutralButton->GetWidth()/2, m_h - mNeutralButton->GetHeight());
        }
        else if (mPositiveButton && mNegativeButton) {
            mPositiveButton->SetPosition(m_w/4 - mPositiveButton->GetWidth()/2, m_h - mPositiveButton->GetHeight());
            mNegativeButton->SetPosition(m_w - m_w/4 - mNegativeButton->GetWidth()/2, m_h - mNegativeButton->GetHeight());
        }
        else if(mPositiveButton && mNeutralButton){
            mPositiveButton->SetPosition(m_w/4 - mPositiveButton->GetWidth()/2, m_h - mPositiveButton->GetHeight());
            mNeutralButton->SetPosition(m_w - m_w/4 - mNeutralButton->GetWidth()/2, m_h - mNeutralButton->GetHeight());
        }
        else if(mNegativeButton && mNeutralButton){
            mNeutralButton->SetPosition(m_w/4 - mNeutralButton->GetWidth()/2, m_h - mNeutralButton->GetHeight());
            mNegativeButton->SetPosition(m_w - m_w/4 - mNegativeButton->GetWidth()/2, m_h - mNegativeButton->GetHeight());
        }
        else if(mPositiveButton){
            mPositiveButton->SetPosition(m_w/2 - mPositiveButton->GetWidth()/2, m_h - mPositiveButton->GetHeight());
        }
        else if(mNegativeButton){
            mNegativeButton->SetPosition(m_w/2 - mNegativeButton->GetWidth()/2, m_h - mNegativeButton->GetHeight());
        }
        else if(mNeutralButton){
            mNeutralButton->SetPosition(m_w/2 - mNeutralButton->GetWidth()/2, m_h - mNeutralButton->GetHeight());
        }
        
        AddElement(mPositiveButton);
        AddElement(mNegativeButton);
        AddElement(mNeutralButton);
        
        if (mPositiveButton) {
            mPositiveButton->SetStyle(m_style);
        }
        if (mNegativeButton) {
            mNegativeButton->SetStyle(m_style);
        }
        if (mNeutralButton) {
            mNeutralButton->SetStyle(m_style);
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
        return mIsOpen;
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
            int y = m_y + Style::DEFAULT_MARGIN;
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