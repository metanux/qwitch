//---------------------------------------------------------------------
// 
//  
// 
//
#include "Camera.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
Camera::Camera()
{
    //mPos.move(-300, -100, 0);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Camera::update()
{
    double dx = (mPos.x() - mScrollPos.x()) / -10;
    double dy = (mPos.y() - mScrollPos.y()) / -10;
    double dz = (mPos.z() - mScrollPos.z()) / -10;
    mPos.move(dx, dy, dz);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Camera::setScrollPos(const Vector3d& aPos)
{
    mScrollPos.setX(aPos.x());
    mScrollPos.setY(aPos.y());
    mScrollPos.setZ(aPos.z());
}

//---------------------------------------------------------------------
// 
//  
// 
//
const Vector3d& Camera::pos() const
{
    return mPos;
}

} // namespace game
} // namespace qwitch