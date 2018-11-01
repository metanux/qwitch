//---------------------------------------------------------------------
// 
//  
// 
//
#include "ObjectImage.hpp"
#include "DxLib.h"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
ObjectImage::ObjectImage()
    : mHandl()
    , mPos()
    , mSize()
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
double ObjectImage::convertWindowPosX() const
{
    double posX = 0;
    posX += mPos.x();
    posX -= mPos.y();
    posX -= mSize.y();
    return posX;
}
//---------------------------------------------------------------------
double ObjectImage::convertWindowPosY() const
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
void ObjectImage::setHandl(int aHandl)
{
    mHandl = aHandl;
}
//---------------------------------------------------------------------
void ObjectImage::setPos(double aX, double aY, double aZ)
{
    mPos.setX(aX);
    mPos.setY(aY);
    mPos.setZ(aZ);
}
//---------------------------------------------------------------------
void ObjectImage::setPos(const Vector3d& aPos)
{
    setPos(aPos.x(), aPos.y(), aPos.z());
}
//---------------------------------------------------------------------
void ObjectImage::setSize(double aX, double aY, double aZ)
{
    mSize.setX(aX);
    mSize.setY(aY);
    mSize.setZ(aZ);
}
//---------------------------------------------------------------------
void ObjectImage::setSize(const Vector3d& aSize)
{
    setSize(aSize.x(), aSize.y(), aSize.z());
}

//---------------------------------------------------------------------
// 
//  
// 
//
int ObjectImage::handl() const
{
    return mHandl;
}
//---------------------------------------------------------------------
const Vector3d& ObjectImage::pos() const
{
    return mPos;
}
//---------------------------------------------------------------------
const Vector3d& ObjectImage::size() const
{
    return mSize;
}

} // namespace game
} // namespace qwitch