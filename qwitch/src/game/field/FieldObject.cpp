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
    : mPos()
    , mSize()
    , mForce()
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
void FieldObject::move(const Vector3d& aPos)
{
    mPos += aPos;
}

//---------------------------------------------------------------------
// 
//  
// 
//
void FieldObject::addForce(const Vector3d& aForce)
{
    mForce += aForce;
}

//---------------------------------------------------------------------
// 
//  
// 
//
double FieldObject::convertWindowPosX() const
{
    double posX = 0;
    posX += mPos.x();
    posX -= mPos.y();
    posX -= mSize.x();
    return posX;
}
//---------------------------------------------------------------------
double FieldObject::convertWindowPosY() const
{
    double posY = 0;
    posY += mPos.x() / 2;
    posY += mPos.y() / 2;
    posY -= mPos.z();
    posY -= mSize.z();
    return posY;
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
void FieldObject::setForce(const Vector3d& aForce)
{
    mForce = aForce;
}
//---------------------------------------------------------------------
void FieldObject::setForceX(double aX)
{
    mForce.setX(aX);
}
//---------------------------------------------------------------------
void FieldObject::setForceY(double aY)
{
    mForce.setY(aY);
}
//---------------------------------------------------------------------
void FieldObject::setForceZ(double aZ)
{
    mForce.setZ(aZ);
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
//---------------------------------------------------------------------
const Vector3d& FieldObject::force() const
{
    return mForce;
}

} // namespace game
} // namespace qwitch