//---------------------------------------------------------------------
// 
//  
// 
//
#include "Block.hpp"
#include "assets/Images.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
const int Block::PIXEL_SIZE = 32;

//---------------------------------------------------------------------
// 
//  
// 
//
Block::Block()
    : mKind()
{
    addImage(0);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Block::update()
{
    setImageHandl(0, Images::ins().block(mKind));
    setImagePos(0, pos());
    setImageSize(0, size());
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Block::setKind(int aKind)
{
    mKind = aKind;
}
//---------------------------------------------------------------------
void Block::setGroup(
    int aId,
    const Vector3d& aPos,
    const Vector3d& aSize)
{
    mGroupId = aId;
    mGroupPos = aPos;
    mGroupSize = aSize;
}

//---------------------------------------------------------------------
// 
//  
// 
//
int Block::groupId() const
{
    return mGroupId;
}
//---------------------------------------------------------------------
const Vector3d& Block::groupPos() const
{
    return mGroupPos;
}
//---------------------------------------------------------------------
const Vector3d& Block::groupSize() const
{
    return mGroupSize;
}

} // namespace game
} // namespace qwitch