//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include <vector>

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
class Status {
public:
    Status();

    /// HPを減らす
    void reduceHp(int aValue);

    /// getter
    int hp() const;
    int attack() const;
    double moveSpeed() const;
    double jumpPower() const;

private:
    /// 現在のHP
    int mHp;
    /// 現在の基礎魔法攻撃力
    int mAttack;
    /// 移動速度
    double mMoveSpeed;
    /// ジャンプ力
    double mJumpPower;
};

} // namespace game
} // namespace qwitch