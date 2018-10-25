﻿//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "game/field/FieldObject.hpp"
#include "game/field/character/Status.hpp"
#include "game/field/character/Magic.hpp"
#include <vector>

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
class Character : public FieldObject {
public:
    /// コンストラクタ
    Character();

    /// ダメージ処理
    void receiveDamage(int aDamage);
    /// MPの消費
    void reduceMp(int aValue);

    /// setter
    void setMagicIndex(int aIndex);

    /// getter
    int image() const;
    const Status& status() const;
    const Magic& activeMagic(int aIndex) const;
    const Magic& passiveMagic(int aIndex) const;
    int magicIndex() const;

private:
    /// ステータス
    Status mStatus;
    /// アクティブ魔法0~9
    std::vector<Magic> mActiveMagic;
    /// パッシブ魔法
    std::vector<Magic> mPassiveMagic;
    /// 詠唱中のアクティブ魔法index
    int mMagicIndex;
    /// 装備
};

} // namespace game
} // namespace qwitch