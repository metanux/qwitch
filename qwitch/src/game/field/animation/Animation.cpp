//---------------------------------------------------------------------
// 
//  
// 
//
#include "Animation.hpp"
#include "DxLib.h"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
Animation::Animation()
    : mKindToAnime()
    , mKind(Kind_Wait)
    , mNextKind(Kind_Wait)
    , mAnimeIndex(0)
    , mImageIndex(0)
    , mFrame(0)
    , mImageNum(4)
    , mSpeed(20)
{
    // デバッグ用
    mKindToAnime[Kind_Wait] = 0;
    mKindToAnime[Kind_Walk] = 1;
    mKindToAnime[Kind_Rise] = 2;
    mKindToAnime[Kind_Fall] = 3;
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Animation::update()
{
    //----- 経過フレームの更新
    mFrame++;

    //----- アニメーションの更新
    change(mNextKind);

    //----- 画像の更新
    if (isNextIndex()) {
        nextIndex();
    }
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Animation::setNextKind(Kind aKind)
{
    //----- アニメーションの優先順位に基づいて設定
    if (aKind == Kind_Walk) {
        if (mNextKind == Kind_Wait) {
            mNextKind = aKind;
        }
    }
    if (aKind == Kind_Rise) {
        if (mNextKind == Kind_Wait) {
            mNextKind = aKind;
        }
        if (mNextKind == Kind_Walk) {
            mNextKind = aKind;
        }
    }
    if (aKind == Kind_Fall) {
        if (mNextKind == Kind_Wait) {
            mNextKind = aKind;
        }
        if (mNextKind == Kind_Walk) {
            mNextKind = aKind;
        }
    }
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Animation::change(Kind aKind)
{
    mNextKind = Kind_Wait;
    if (mKind == aKind) { return; }
    mKind = aKind;
    mAnimeIndex = mKindToAnime[aKind];
    mImageIndex = 0;
    mFrame = 0;
    mImageNum = 4;
    mSpeed = 20;
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Animation::nextIndex()
{
    mImageIndex = (mImageIndex + 1) % mImageNum;
    mFrame = 0;
}

//---------------------------------------------------------------------
// 
//  
// 
//
bool Animation::isNextIndex()
{
    return (mFrame >= mSpeed);
}

//---------------------------------------------------------------------
// 
//  
// 
//
int Animation::animeIndex() const
{
    return mAnimeIndex;
}
//---------------------------------------------------------------------
int Animation::imageIndex() const
{
    return mImageIndex;
}

} // namespace game
} // namespace qwitch