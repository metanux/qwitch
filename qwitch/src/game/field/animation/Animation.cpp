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
    : mKind(0)
    , mIndex(0)
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
    mKind = aKind;
    mIndex = 0;
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
    mIndex = (mIndex + 1) % mImageNum;
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
int Animation::kind() const
{
    return mKind;
}
//---------------------------------------------------------------------
int Animation::index() const
{
    return mIndex;
}

} // namespace game
} // namespace qwitch