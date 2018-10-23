//---------------------------------------------------------------------
// 
//  
// 
//
#include "DamageEffects.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
DamageEffects::DamageEffects()
    : mEffects()
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
void DamageEffects::update()
{
    //----- 状態の更新
    int c = count();
    for (int i = 0; i < c; i++) {
        mEffects[i].update();
    }

    //----- 削除処理
    for (int i = c - 1; i >= 0; i--) {
        if (mEffects[i].isDelete()) {
            mEffects.erase(mEffects.begin() + i);
        }
    }
}

//---------------------------------------------------------------------
// 
//  
// 
//
void DamageEffects::add(int aDamage, int aWindowPosX, int aWindowPosY)
{
    DamageEffect effect;
    effect.setDamage(aDamage);
    effect.setWindowPos(aWindowPosX, aWindowPosY);
    effect.decideForce();
    mEffects.push_back(effect);
}

//---------------------------------------------------------------------
// 
//  
// 
//
int DamageEffects::count() const
{
    return (int)mEffects.size();
}

//---------------------------------------------------------------------
// 
//  
// 
//
const DamageEffect& DamageEffects::effect(int aIndex) const
{
    return mEffects[aIndex];
}

} // namespace game
} // namespace qwitch