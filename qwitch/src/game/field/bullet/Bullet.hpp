//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "game/field/object/FieldObject.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
class Bullet : public FieldObject {
public:
    /// コンストラクタ
    Bullet();

    /// 更新処理
    void update();

    ///
    bool isDelete() const;

    /// setter
    void setAttackPower(int aAttackPower);

    /// getter
    int image() const;
    int attackPower() const;

private:
    /// 経過フレーム
    int mFrame;
    /// 攻撃力量
    int mAttackPower;
};

} // namespace game
} // namespace qwitch