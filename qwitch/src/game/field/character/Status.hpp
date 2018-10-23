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

    /// getter
    int hp() const;
    double moveSpeed() const;
    double jumpPower() const;

private:
    /// 現在のHP
    int mHp;
    /// 移動速度
    double mMoveSpeed;
    /// ジャンプ力
    double mJumpPower;
};

} // namespace game
} // namespace qwitch