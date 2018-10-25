﻿//---------------------------------------------------------------------
// 
//  
// 
//
#include "Bullet.hpp"
#include "assets/Images.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
Bullet::Bullet()
    : mFrame(0)
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Bullet::update()
{
    FieldObject::update();

    mFrame++;
}

//---------------------------------------------------------------------
// 
//  
// 
//
bool Bullet::isDelete() const
{
    return (mFrame >= 100);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Bullet::setAttackPower(int aAttackPower)
{
    mAttackPower = aAttackPower;
}

//---------------------------------------------------------------------
// 
//  
// 
//
int Bullet::image() const
{
    return Images::ins().bullet(0, 0, 0);
}
//---------------------------------------------------------------------
int Bullet::attackPower() const
{
    return mAttackPower;
}


} // namespace game
} // namespace qwitch