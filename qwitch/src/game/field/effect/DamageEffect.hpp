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

    /// 乱数でforceの設定
    void decideForce();

    /// 削除判定
    bool isDelete() const;

    /// setter
    void setWindowPos(int aX, int aY);
    void setDamage(int aDamage);

    /// getter
    double windowPosX() const;
    double windowPosY() const;
    int damage() const;

private:
    /// member
    double mWindowPosX;
    double mWindowPosY;
    /// 
    double forceX;
    double forceY;
    /// ダメージ量
    int mDamage;
    /// 経過フレーム数
    int mFrame;
};

} // namespace game
} // namespace qwitch