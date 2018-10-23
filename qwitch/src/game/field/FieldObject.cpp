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
    , mKind(0)
    , mDirection(Direction_Down)
    , mAnimation()
{
    static int idList = 0;
    mId = idList++;
}

//---------------------------------------------------------------------
// 
//  
// 
//
void FieldObject::update()
{
    mAnimation.update();
}

//---------------------------------------------------------------------
// 
//  
// 
//
bool FieldObject::isCollision(const FieldObject& aObject) const
{
    return isCollision(aObject.pos(), aObject.size());
}
//---------------------------------------------------------------------
bool FieldObject::isCollision(
    const Vector3d& aPos,
    const Vector3d& aSize) const
{
    int x11 = (int)mPos.x();
    int y11 = (int)mPos.y();
    int z11 = (int)mPos.z();
    int x12 = x11 + (int)mSize.x();
    int y12 = y11 + (int)mSize.y();
    int z12 = z11 + (int)mSize.z();
    int x21 = (int)aPos.x();
    int y21 = (int)aPos.y();
    int z21 = (int)aPos.z();
    int x22 = x21 + (int)aSize.x();
    int y22 = y21 + (int)aSize.y();
    int z22 = z21 + (int)aSize.z();

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
void FieldObject::setAnimation(Animation::Kind aKind)
{
    mAnimation.setNextKind(aKind);
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
void FieldObject::setKind(int aKind)
{
    mKind = aKind;
}
//---------------------------------------------------------------------
void FieldObject::setDirection(int aX, int aY, int aZ)
{
    if (aX < 0) {
        if (aY < 0) { mDirection = Direction_Up; }
        if (aY == 0) { mDirection = Direction_LeftUp; }
        if (aY > 0) { mDirection = Direction_Left; }
    }
    else if (aX > 0) {
        if (aY < 0) { mDirection = Direction_Right; }
        if (aY == 0) { mDirection = Direction_RightDown; }
        if (aY > 0) { mDirection = Direction_Down; }
    }
    else {
        if (aY < 0) { mDirection = Direction_RightUp; }
        if (aY > 0) { mDirection = Direction_LeftDown; }
    }
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
//---------------------------------------------------------------------
int FieldObject::kind() const
{
    return mKind;
}
//---------------------------------------------------------------------
FieldObject::Direction FieldObject::direction() const
{
    return mDirection;
}
//---------------------------------------------------------------------
const Animation& FieldObject::animation() const
{
    return mAnimation;
}
//---------------------------------------------------------------------
Vector3d FieldObject::attackAreaPos() const
{
    Vector3d areaPos = pos();
    double sx = size().x();
    double sy = size().y();
    double sz = size().z();
    double dx = 0;
    double dy = 0;
    double dz = 0;

    if (mDirection == Direction_Down) {
        dx = sx / 2;
        dy = sy / 2;
    }
    else if (mDirection == Direction_LeftDown) {
        dx = 0;
        dy = sy;
    }
    else if (mDirection == Direction_Left) {
        dx = sx / 2 * -1;
        dy = sy / 2;
    }
    else if (mDirection == Direction_LeftUp) {
        dx = sx * -1;
        dy = 0;
    }
    else if (mDirection == Direction_Up) {
        dx = sx / 2 * -1;
        dy = sy / 2 * -1;
    }
    else if (mDirection == Direction_RightUp) {
        dx = 0;
        dy = sy * -1;
    }
    else if (mDirection == Direction_Right) {
        dx = sx / 2;
        sy = sy / 2 * -1;
    }
    else if (mDirection == Direction_RightDown) {
        dx = sx;
        dy = 0;
    }

    //----- 
    areaPos.move(dx, dy, dz);

    return areaPos;
}
//---------------------------------------------------------------------
Vector3d FieldObject::attackAreaSize() const
{
    double sx = size().x();
    double sy = size().y();
    double sz = size().z();
    Vector3d areaSize(sx, sy, sz);
    return areaSize;
}

} // namespace game
} // namespace qwitch