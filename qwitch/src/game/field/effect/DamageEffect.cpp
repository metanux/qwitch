//---------------------------------------------------------------------
// 
//  
// 
//
#include "DamageEffect.hpp"
#include "DxLib.h"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
DamageEffect::DamageEffect()
    : mWindowPosX(0)
    , mWindowPosY(0)
    , forceX(0)
    , forceY(0)
    , mDamage(0)
    , mFrame(0)
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
void DamageEffect::update()
{
    //----- 位置更新
    mWindowPosX += forceX;
    mWindowPosY += forceY;

    //----- 
    forceY += 0.20;

    //----- 経過フレーム更新
    mFrame++;
}

//---------------------------------------------------------------------
// 
//  
// 
//
void DamageEffect::decideForce()
{
    forceX = DxLib::GetRand(9) / 3.0 - 1.5;
    forceY = -3.0 + DxLib::GetRand(20) / -10.0;
}

//---------------------------------------------------------------------
// 
//  
// 
//
bool DamageEffect::isDelete() const
{
    return (mFrame >= 50);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void DamageEffect::setWindowPos(int aX, int aY)
{
    mWindowPosX = aX;
    mWindowPosY = aY;
}
//---------------------------------------------------------------------
void DamageEffect::setDamage(int aDamage)
{
    mDamage = aDamage;
}

//---------------------------------------------------------------------
// 
//  
// 
//
double DamageEffect::windowPosX() const
{
    return mWindowPosX;
}
//---------------------------------------------------------------------
double DamageEffect::windowPosY() const
{
    return mWindowPosY;
}
//---------------------------------------------------------------------
int DamageEffect::damage() const
{
    return mDamage;
}


} // namespace game
} // namespace qwitch