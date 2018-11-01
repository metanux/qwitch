//---------------------------------------------------------------------
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
    addImage(0);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Bullet::update()
{
    FieldObject::update();

    int handl = Images::ins().bullet(0, 0, 0);
    setImageHandl(0, handl);
    setImagePos(0, pos());
    setImageSize(0, size());

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
int Bullet::attackPower() const
{
    return mAttackPower;
}


} // namespace game
} // namespace qwitch