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
    //----- ブロック
    loadBlock();

    //----- キャラクター
    loadCharacter();

    //----- タイトル画面
    mTitleBack = DxLib::LoadGraph("assets/images/title/back.png");
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Images::loadBlock()
{
    char url[100];

    int blockNum = 2;
    mBlock.resize(blockNum);
    for (int i = 0; i < blockNum; i++) {
        sprintf_s(url, "assets/images/block/%d.png", i);
        mBlock[i] = DxLib::LoadGraph(url);
    }
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Images::loadCharacter()
{
    char url[100];

    for (int kind = 0; kind < 2; kind++) {
        std::vector<std::vector<int>> animeImages;
        for (int anime = 0; anime < 1; anime++) {
            std::vector<int> images;
            int imageNumX = 4;
            int imageNumY = 4;
            int imageSizeX = 64;
            int imageSizeY = 96;
            int imageNum = imageNumX * imageNumY;
            sprintf_s(url, "assets/images/character/%d/%d.png", kind, anime);
            int imageTmp[30];
            DxLib::LoadDivGraph(url, imageNum, imageNumX, imageNumY, imageSizeX, imageSizeY, imageTmp);
            for (int i = 0; i < imageNum; i++) {
                images.push_back(imageTmp[i]);
            }
            animeImages.push_back(images);
        }
        mCharacter.push_back(animeImages);
    }
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
int Images::character(int aKind, int aAnime, int aDirection, int aIndex) const
{
    int index = aDirection * 4 + aIndex;
    return mCharacter[aKind][aAnime][index];
}
//---------------------------------------------------------------------
int Images::titleBack() const
{
    return mTitleBack;
}

} // namespace qwitch