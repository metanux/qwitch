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
    char url[100];

    //----- ブロック
    int blockNum = 2;
    mBlock.resize(blockNum);
    for (int i = 0; i < blockNum; i++) {
        sprintf_s(url, "assets/images/block/%d.png", i);
        mBlock[i] = DxLib::LoadGraph(url);
    }

    //----- キャラクター
    for (int i = 0; i < 2; i++) {
        sprintf_s(url, "assets/images/character/%d.png", i);
        int image = DxLib::LoadGraph(url);
        mCharacter.push_back(image);
    }

    //----- タイトル画面
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