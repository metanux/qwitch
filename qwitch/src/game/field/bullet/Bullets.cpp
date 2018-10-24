//---------------------------------------------------------------------
// 
//  
// 
//
#include "Bullets.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
Bullets::Bullets()
    : mBullet()
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Bullets::update()
{
    //----- 状態の更新
    int n = count();
    for (int i = 0; i < n; i++) {
        mBullet[i].update();
    }

    //----- 移動処理
    for (int i = 0; i < n; i++) {
        int speed = 3;
        int x = mBullet[i].directionX() * speed;
        int y = mBullet[i].directionY() * speed;
        mBullet[i].move(Vector3d(x, y, 0));
    }
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Bullets::add(
    const Vector3d& aPos,
    FieldObject::Direction aDirection,
    int aKind)
{
    Bullet bullet;
    bullet.setPos(aPos);
    bullet.setSize(Vector3d(16, 16, 16));
    bullet.setKind(aKind);
    bullet.setDirection(aDirection);
    mBullet.push_back(bullet);
    printf("add Bullet\n");
}

//---------------------------------------------------------------------
// 
//  
// 
//
int Bullets::count() const
{
    return (int)mBullet.size();
}

//---------------------------------------------------------------------
// 
//  
// 
//
const Bullet& Bullets::bullet(int aIndex) const
{
    return mBullet[aIndex];
}

} // namespace game
} // namespace qwitch