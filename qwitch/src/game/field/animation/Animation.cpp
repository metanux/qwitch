//---------------------------------------------------------------------
// 
//  
// 
//
#include "Animation.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
Animation::Animation()
    : mAnimeIndex(0)
    , mImageIndex(0)
    , mFrame(0)
    , mImageNum(4)
    , mSpeed(20)
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Animation::update()
{
    //-----
    mFrame++;

    //-----
    if (isNextIndex()) {
        nextIndex();
    }
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Animation::change(int aKind)
{
    mAnimeIndex = aKind;
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