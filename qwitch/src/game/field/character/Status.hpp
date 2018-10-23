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

private:
    /// 現在のHP
    int mHp;
    /// 移動速度
    double mMoveSpeed;
};

} // namespace game
} // namespace qwitch