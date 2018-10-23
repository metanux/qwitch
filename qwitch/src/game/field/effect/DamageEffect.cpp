//---------------------------------------------------------------------
// 
//  
// 
//
#include "DamageEffect.hpp"

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
int DamageEffect::windowPosX() const
{
    return mWindowPosX;
}
//---------------------------------------------------------------------
int DamageEffect::windowPosY() const
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