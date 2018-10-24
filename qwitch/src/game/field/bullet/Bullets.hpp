//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "game/field/bullet/Bullet.hpp"
#include <vector>

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
class Bullets {
public:
    /// コンストラクタ
    Bullets();

    /// 更新処理
    void update();

    /// オブジェクト追加処理
    void add(
        const Vector3d& aPos,
        int aKind);

    /// オブジェクト数
    int count() const;

    /// getter
    const Bullet& bullet(int aIndex) const;

private:
    std::vector<Bullet> mBullet;

};

} // namespace game
} // namespace qwitch