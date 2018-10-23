//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "util/Vector3d.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
class DamageEffect {
public:
    /// コンストラクタ
    DamageEffect();

    /// 更新処理
    void update();

    /// setter
    void setWindowPos(int aX, int aY);
    void setDamage(int aDamage);

    /// getter
    int windowPosX() const;
    int windowPosY() const;
    int damage() const;

private:
    /// member
    int mWindowPosX;
    int mWindowPosY;
    /// ダメージ量
    int mDamage;
    /// 経過フレーム数
    int mFrame;
};

} // namespace game
} // namespace qwitch