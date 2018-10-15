//---------------------------------------------------------------------
// 
//  
// 
//
#include "Images.hpp"
#include "DxLib.h"

namespace qwitch {

//---------------------------------------------------------------------
// 
//  
// 
//
Images::Images()
    : mBlock()
    , mTitleBack()
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
Images& Images::ins()
{
    static Images instance;
    return instance;
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Images::load()
{
    //-----
    for (int i = 0; i < 1; i++) {
        int image = DxLib::LoadGraph("assets/images/block/0.png");
        mBlock.push_back(image);
    }

    //-----
    for (int i = 0; i < 1; i++) {
        int image = DxLib::LoadGraph("assets/images/character/0.png");
        mCharacter.push_back(image);
    }

    //-----
    mTitleBack = DxLib::LoadGraph("assets/images/title/back.png");
}

//---------------------------------------------------------------------
// 
//  
// 
//
int Images::block(int aIndex) const
{
    return mBlock[aIndex];
}
//---------------------------------------------------------------------
int Images::character(int aIndex) const
{
    return mCharacter[aIndex];
}
//---------------------------------------------------------------------
int Images::titleBack() const
{
    return mTitleBack;
}

} // namespace qwitch