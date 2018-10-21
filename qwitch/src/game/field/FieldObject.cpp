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
    : mId()
    , mPos()
    , mSize()
    , mForce()
{
    static int idList = 0;
    mId = idList++;
}

//---------------------------------------------------------------------
// 
//  
// 
//
bool FieldObject::isCollision(const FieldObject& aObject) const
{
    int x11 = (int)mPos.x();
    int y11 = (int)mPos.y();
    int z11 = (int)mPos.z();
    int x12 = x11 + (int)mSize.x();
    int y12 = y11 + (int)mSize.y();
    int z12 = z11 + (int)mSize.z();
    int x21 = (int)aObject.pos().x();
    int y21 = (int)aObject.pos().y();
    int z21 = (int)aObject.pos().z();
    int x22 = x21 + (int)aObject.size().x();
    int y22 = y21 + (int)aObject.size().y();
    int z22 = z21 + (int)aObject.size().z();

    if (x11 >= x22) { return false; }
    if (x12 <= x21) { return false; }
    if (y11 >= y22) { return false; }
    if (y12 <= y21) { return false; }
    if (z11 >= z22) { return false; }
    if (z12 <= z21) { return false; }
    return true;
}

//---------------------------------------------------------------------
// 
//  
// 
//
bool FieldObject::isEqual(const FieldObject& aObject) const
{
    if (aObject.id() == mId) { return true; }
    return false;
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
int FieldObject::id() const
{
    return mId;
}
//---------------------------------------------------------------------
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