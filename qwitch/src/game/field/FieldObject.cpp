//---------------------------------------------------------------------
// 
//  
// 
//
#include "FieldObject.hpp"
#include <stdio.h>
namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
FieldObject::FieldObject()
{
    printf("objectCreate\n");
}

//---------------------------------------------------------------------
// 
//  
// 
//
void FieldObject::setPos(const Vector3d& aPos)
{
    mPos = aPos;
}
//---------------------------------------------------------------------
void FieldObject::setSize(const Vector3d& aSize)
{
    mSize = aSize;
}

//---------------------------------------------------------------------
// 
//  
// 
//
const Vector3d& FieldObject::pos() const
{
    return mPos;
}
//---------------------------------------------------------------------
const Vector3d& FieldObject::size() const
{
    return mSize;
}

} // namespace game
} // namespace qwitch