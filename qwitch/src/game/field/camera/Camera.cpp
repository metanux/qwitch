﻿//---------------------------------------------------------------------
// 
//  
// 
//
#include "Camera.hpp"
#include "system/System.hpp"
#include "DxLib.h"
#include "game/field/terrain/Block.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
Camera::Camera()
    : mFieldPos()
    , mScrollPos()
    , mWindowPos()
{
    mFieldPos.move(768, 768, 32);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Camera::update()
{
    updatePos();
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Camera::update(const FieldObject& aObject)
{
    //----- スクロール位置更新
    /*
    double posX = 0;
    posX -= System::ins().windowSizeX() / 2;
    posX += aObject.convertWindowPosX();

    double posY = 0;
    posY -= System::ins().windowSizeY() / 2;
    posY += aObject.convertWindowPosY();

    mScrollPos.setX(posX);
    mScrollPos.setY(posY);
    */
    mScrollPos = aObject.pos();

    //----- 更新
    update();
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Camera::updatePos()
{
    //----- スクロール
    double dx = (mFieldPos.x() - mScrollPos.x()) / -10;
    double dy = (mFieldPos.y() - mScrollPos.y()) / -10;
    double dz = (mFieldPos.z() - mScrollPos.z()) / -10;
    mFieldPos.move(dx, dy, dz);

    //----- ウィンドウ座標の設定
    double posX = 0;
    posX += mFieldPos.x();
    posX -= mFieldPos.y();
    posX -= System::ins().windowSizeX() / 2;
    mWindowPos.setX(posX);

    double posY = 0;
    posY += mFieldPos.x() / 2;
    posY += mFieldPos.y() / 2;
    posY -= mFieldPos.z();
    posY -= System::ins().windowSizeY() / 2;
    mWindowPos.setY(posY);
}

//---------------------------------------------------------------------
// 
//  
// 
//
const Vector3d& Camera::windowPos() const
{
    return mWindowPos;
}
//---------------------------------------------------------------------
const Vector3d& Camera::fieldPos() const
{
    return mFieldPos;
}

} // namespace game
} // namespace qwitch