//---------------------------------------------------------------------
// 
//  
// 
//
#include "FieldObject.hpp"
#include <unordered_map>

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
    , mRelation(Relation_Neutral)
    , mImmutableOrder()
    , mDynamicOrder()
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
    mMovedFlag = false;
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
bool FieldObject::isEnemy(const FieldObject& aObject) const
{
    if (aObject.relation() == Relation_Enemy) {
        if (mRelation == Relation_Friend) {
            return true;
        }
    }
    if (aObject.relation() == Relation_Friend) {
        if (mRelation == Relation_Enemy) {
            return true;
        }
    }
    return false;
}

//---------------------------------------------------------------------
// 
//  
// 
//
bool FieldObject::isMoved() const
{
    return mMovedFlag;
}

//---------------------------------------------------------------------
// 
//  
// 
//
bool FieldObject::isPreRender(const FieldObject& aObject) const
{
    int x1min = (int)(mPos.x());
    int y1min = (int)(mPos.y());
    int z1min = (int)(mPos.z());
    int x2max = (int)(aObject.pos().x() + aObject.size().x());
    int y2max = (int)(aObject.pos().y() + aObject.size().y());
    int z2max = (int)(aObject.pos().z() + aObject.size().z());

    return ((x1min < x2max) && (y1min < y2max) && (z1min < z2max));
}

//---------------------------------------------------------------------
// 
//  
// 
//
void FieldObject::move(const Vector3d& aPos)
{
    mPos += aPos;
    mMovedFlag = true;
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
    posX -= mSize.y();
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
void FieldObject::addImage(int aHandl)
{
    ObjectImage image;
    image.setHandl(aHandl);
    mImages.push_back(image);
}
//---------------------------------------------------------------------
void FieldObject::addImage(
    int aHandl,
    const Vector3d& aPos,
    const Vector3d& aSize)
{
    ObjectImage image;
    image.setHandl(aHandl);
    image.setPos(aPos);
    image.setSize(aSize);
    mImages.push_back(image);
}
//---------------------------------------------------------------------
void FieldObject::setImageHandl(int aIndex, int aHandl)
{
    mImages[aIndex].setHandl(aHandl);
}
//---------------------------------------------------------------------
void FieldObject::setImagePos(
    int aIndex,
    const Vector3d& aPos)
{
    mImages[aIndex].setPos(aPos);
}
//---------------------------------------------------------------------
void FieldObject::setImageSize(
    int aIndex,
    const Vector3d& aSize)
{
    mImages[aIndex].setSize(aSize);
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
void FieldObject::setDirection(Direction aDirection)
{
    mDirection = aDirection;
}
//---------------------------------------------------------------------
void FieldObject::setRelation(Relation aRelation)
{
    mRelation = aRelation;
}
//---------------------------------------------------------------------
void FieldObject::setAnimeSpeed(int aSpeed)
{
    mAnimation.setNextSpeed(aSpeed);
}
//---------------------------------------------------------------------
void FieldObject::setImmutableOrder(int aObjectId, int aValue)
{
    mImmutableOrder[aObjectId] = aValue;
}
//---------------------------------------------------------------------
void FieldObject::setDynamicOrder(int aObjectId, int aValue)
{
    mDynamicOrder[aObjectId] = aValue;
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
const std::vector<ObjectImage>& FieldObject::images() const
{
    return mImages;
}
//---------------------------------------------------------------------
FieldObject::Direction FieldObject::direction() const
{
    return mDirection;
}
//---------------------------------------------------------------------
int FieldObject::directionX() const
{
    if (mDirection == Direction_Down) { return 1; }
    if (mDirection == Direction_LeftDown) { return 0; }
    if (mDirection == Direction_Left) { return -1; }
    if (mDirection == Direction_LeftUp) { return -1; }
    if (mDirection == Direction_Up) { return -1; }
    if (mDirection == Direction_RightUp) { return 0; }
    if (mDirection == Direction_Right) { return 1; }
    if (mDirection == Direction_RightDown) { return 1; }
    return 0;
}
//---------------------------------------------------------------------
int FieldObject::directionY() const
{
    if (mDirection == Direction_Down) { return 1; }
    if (mDirection == Direction_LeftDown) { return 1; }
    if (mDirection == Direction_Left) { return 1; }
    if (mDirection == Direction_LeftUp) { return 0; }
    if (mDirection == Direction_Up) { return -1; }
    if (mDirection == Direction_RightUp) { return -1; }
    if (mDirection == Direction_Right) { return -1; }
    if (mDirection == Direction_RightDown) { return 0; }
    return 0;
}
//---------------------------------------------------------------------
const Animation& FieldObject::animation() const
{
    return mAnimation;
}
//---------------------------------------------------------------------
FieldObject::Relation FieldObject::relation() const
{
    return mRelation;
}
//---------------------------------------------------------------------
int FieldObject::order(int aObjectId) const
{
    std::unordered_map<int, int>::const_iterator pos;
    pos = mImmutableOrder.find(aObjectId);
    return pos->second;
}

} // namespace game
} // namespace qwitch