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

    /// 死亡判定
    bool isDeath() const;

    /// getter
    int hp() const;
    int hpMax() const;
    double hpRate() const;
    int mp() const;
    int mpMax() const;
    double mpRate() const;
    int attack() const;
    double moveSpeed() const;
    double jumpPower() const;

private:
    /// 現在のHP
    int mHp;
    /// 最大HP
    int mHpMax;
    /// 現在のMP
    int mMp;
    /// 最大MP
    int mMpMax;
    /// 現在の基礎魔法攻撃力
    int mAttack;
    /// 移動速度
    double mMoveSpeed;
    /// ジャンプ力
    double mJumpPower;
};

} // namespace game
} // namespace qwitch