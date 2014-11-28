//
//  Dialog.cpp
//  n8_Game
//
//  Created by Nate Ebel on 11/9/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#include "Dialog.h"

gui::Dialog::Dialog(n8::Window* p_window, int p_x, int p_y, int p_w, int p_h ) : Container(p_window, "",p_x,p_y,p_w,p_h)
{
    mTitle = "";
    mIsOpen = false;
    mResult = Dialog::EResultCode::NEUTRAL;
    mDismissedListener = nullptr;
    mPositiveButton = nullptr;
    mNegativeButton = nullptr;
    mNeutralButton = nullptr;
}

gui::Dialog::~Dialog(){
    Container::~Container();
    
    m_window = nullptr;
    
    mDismissedListener = nullptr;
    mPositiveListener = nullptr;
    mNegativeListener = nullptr;
    mNeutralListener = nullptr;
    if (mPositiveButton) {
        delete mPositiveButton;
        mPositiveButton = nullptr;
    }
    
    if (mNegativeButton) {
        delete mNegativeButton;
        mNegativeButton = nullptr;
    }
    
    if (mNeutralButton) {
        delete mNeutralButton;
        mNeutralButton = nullptr;
    }
    
}

void gui::Dialog::SetIsOpen(){
    mIsOpen = true;
}

void gui::Dialog::SetTitle(std::string title){
    mTitle = title;
}

bool gui::Dialog::CheckMouseClickDown(int pX, int pY){
    bool clickedWithinDialog = positionWithinElement(pX, pY);
    
    // If the click was not within the bounds of the dialog, we return false so it may be dismissed
    if (!clickedWithinDialog) {
        return false;
    }
    
    // If the click was within the dialog, we forward the click on to the dialog's child elements
    Container::CheckMouseClickDown(pX, pY);
    
    // Return true when the click was within the bounds of the dialog
    return true;
}

bool gui::Dialog::CheckMouseClickUp(int pX, int pY){
    bool clickedUpWithDialog = positionWithinElement(pX, pY);
    if (!clickedUpWithDialog) {
        return false;
    }
    
    Container::CheckMouseClickUp(pX, pY);
    
    return true;
}

bool gui::Dialog::CheckMouseMove(int pX, int py){
    
    return Container::CheckMouseMove(pX, py);
}

void gui::Dialog::SetPositiveButton(std::string text, std::function<void()> function){
    return SetPositiveButton(text, Style::DEFAULT_BUTTON_WIDTH, Style::DEFAULT_BUTTON_HEIGHT, function);
}

void gui::Dialog::SetPositiveButton(std::string text, int width, int height, std::function<void()> function){
    mPositiveButton = new Button(m_window, "positive", text, 0, 0, width, height);
    mPositiveButton->SetTextSize(Style::DEFAULT_DIALOG_BUTTON_FONT_SIZE);
    mPositiveListener = function;
    SetOnPositiveClickedListener(function);
}

void gui::Dialog::SetNegativeButton(std::string text, std::function<void()> function){
    SetNegativeButton(text, Style::DEFAULT_BUTTON_WIDTH, Style::DEFAULT_BUTTON_HEIGHT, function);
}

void gui::Dialog::SetNegativeButton(std::string text, int width, int height, std::function<void()> function){
    mNegativeButton = new Button(m_window, "negative", text, 0, 0, width, height);
    mNegativeButton->SetTextSize(Style::DEFAULT_DIALOG_BUTTON_FONT_SIZE);
    mNegativeListener = function;
    SetOnNegativeClickedListener(function);
}

void gui::Dialog::SetNeutralButton(std::string text, std::function<void()> function){
    SetNeutralButton(text, Style::DEFAULT_BUTTON_WIDTH, Style::DEFAULT_BUTTON_HEIGHT, function);
}

void gui::Dialog::SetNeutralButton(std::string text, int width, int height, std::function<void()> function){
    mNeutralButton = new Button(m_window, "neutral", text, 0, 0, width, height);
    mNeutralButton->SetTextSize(Style::DEFAULT_DIALOG_BUTTON_FONT_SIZE);
    SetOnNeutralClickedListener(function);
}

void gui::Dialog::SetOnPositiveClickedListener(std::function<void()> function){
    mPositiveListener = function;
    mPositiveButton->setClickHandler([this](){
        mIsOpen = false;
        mResult = EResultCode::POSITIVE;
        if (mPositiveListener){
            mPositiveListener();
        }
    });
}

void gui::Dialog::SetOnNegativeClickedListener(std::function<void()> function){
    mNegativeListener = function;
    mNegativeButton->setClickHandler([this](){
        mIsOpen = false;
        mResult = EResultCode::NEGATIVE;
        if (mNegativeListener){
            mNegativeListener();
        }
    });
}

void gui::Dialog::SetOnNeutralClickedListener(std::function<void()> function){
    mNeutralListener = function;
    mNeutralButton->setClickHandler([this](){
        mIsOpen = false;
        mResult = EResultCode::NEUTRAL;
        if (mNeutralListener) {
            mNeutralListener();
        }
    });
}

void gui::Dialog::SetOnDismissListener(std::function<void(EResultCode)> function){
    mDismissedListener = function;
}


bool gui::Dialog::Update(Uint32 p_currentTime){
    Container::Update(p_currentTime);
    return mIsOpen;
}

void gui::Dialog::Draw(n8::Window* pWindow){
    
    Container::Draw(pWindow);
    
    // Set draw color for text
    SDL_Renderer* renderer = const_cast<SDL_Renderer*>(&pWindow->GetRenderer());
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
    
    SDL_RenderDrawRect(renderer, &m_rectangle.GetRect());
    
    if(mTitleTextTexture.HasTexture()){
        int x = m_x + (m_w - mTitleTextTexture.getWidth())/2;
        int y = m_y + Style::DEFAULT_MARGIN;
        mTitleTextTexture.render(renderer, x,y);
    }
}

void gui::Dialog::Dismiss(){
    if (mDismissedListener != nullptr) {
        mDismissedListener(mResult);
    }
}

