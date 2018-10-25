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
    , mNextSpeed(20)
{
    // デバッグ用
    mKindToAnime[Kind_Wait] = 0;
    mKindToAnime[Kind_Walk] = 1;
    mKindToAnime[Kind_Rise] = 2;
    mKindToAnime[Kind_Fall] = 3;
    mKindToAnime[Kind_MagicPrev] = 4;
    mKindToAnime[Kind_Magic] = 5;
    mKindToAnime[Kind_MagicPost] = 5;
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

    //----- アニメーションの変更
    change(mNextKind);

    //----- NextKindの更新
    if (mKind == Kind_MagicPrev ||
        mKind == Kind_Magic ||
        mKind == Kind_MagicPost) {
        mNextKind = mKind;
    }
    else {
        mNextKind = Kind_Wait;
    }

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
    if (aKind == Kind_MagicPrev) {
        if (mNextKind == Kind_Wait) {
            mNextKind = aKind;
        }
        if (mNextKind == Kind_Walk) {
            mNextKind = aKind;
        }
    }
    if (aKind == Kind_MagicPost) {
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
    if (mKind == aKind) { return; }
    mKind = aKind;
    mAnimeIndex = mKindToAnime[aKind];
    mImageIndex = 0;
    mFrame = 0;
    mImageNum = 4;
    mSpeed = mNextSpeed;
    mNextSpeed = 20;
    if (mKind == Kind_Magic) {
        mSpeed = 0;
        mImageNum = 1;
    }
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Animation::nextIndex()
{
    //----- imageIndexの更新
    mImageIndex = (mImageIndex + 1) % mImageNum;
    mFrame = 0;

    //----- animeIndexの更新
    if (mImageIndex == 0) {
        if (mKind == Kind_MagicPrev) {
            mNextKind = Kind_Magic;
        }
        else if (mKind == Kind_Magic) {
            mNextKind = Kind_MagicPost;
        }
        else if (mKind == Kind_MagicPost) {
            mNextKind = Kind_Wait;
        }
    }
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
void Animation::setNextSpeed(int aSpeed)
{
    mNextSpeed = aSpeed;
}

//---------------------------------------------------------------------
// 
//  
// 
//
Animation::Kind Animation::kind() const
{
    return mKind;
}
//---------------------------------------------------------------------
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