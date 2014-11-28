//
//  Dialog.cpp
//  n8_Game
//
//  Created by Nate Ebel on 10/24/14.
//  Copyright (c) 2014 n8Tech. All rights reserved.
//

#include "AlertDialog.h"

namespace gui {
    
    AlertDialog::Builder::Builder(n8::Window* pWindow) : DialogBuilderInterface(pWindow){
        int x = pWindow->GetWidth()/2 - Style::DEFAULT_DIALOG_WIDTH/2;
        int y = pWindow->GetHeight()/2 - Style::DEFAULT_DIALOG_HEIGHT/2;
        mDialog = new AlertDialog(pWindow, x, y, Style::DEFAULT_DIALOG_WIDTH, Style::DEFAULT_DIALOG_HEIGHT);
        DialogBuilderInterface::mDialog = mDialog;
    }
    
    AlertDialog::Builder::~Builder(){
        mDialog = nullptr;
    }
    
    gui::AlertDialog::AlertDialog(n8::Window* p_window, int p_x, int p_y, int p_w, int p_h ) : Dialog(p_window, p_x, p_y, p_w, p_h){
        
    }
    
    AlertDialog::~AlertDialog(){
        Dialog::~Dialog();
    }
    
    void gui::AlertDialog::Build(){
        
        TTF_Font* font = TTF_OpenFont(m_style.GetFontPath().c_str(), Style::DEFAULT_TITLE_HEIGHT);
        
        m_built = mTitleTextTexture.loadFromRenderedText(  const_cast<SDL_Renderer*>(&m_window->GetRenderer()), font, mTitle.c_str(), m_style.GetColor(Style::EStyleColor::Font).GetColor() );
        
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
}