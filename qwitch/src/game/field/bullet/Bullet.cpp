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
{
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

} // namespace game
} // namespace qwitch