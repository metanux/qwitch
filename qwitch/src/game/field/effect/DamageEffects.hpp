//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "game/field/effect/DamageEffect.hpp"
#include <vector>

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
class DamageEffects {
public:
    /// コンストラクタ
    DamageEffects();
    
    /// 更新処理
    void update();

    /// 追加
    void add(int aDamage, int aWindowPosX, int aWindowPosY);

    /// 数
    int count() const;

    /// getter
    const DamageEffect& effect(int aIndex) const;

private:
    /// member
    std::vector<DamageEffect> mEffects;

};

} // namespace game
} // namespace qwitch