//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "game/field/FieldObject.hpp"
#include "game/field/character/Status.hpp"

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

    /// getter
    int image() const;
    const Status& status() const;

private:
    /// ステータス
    Status mStatus;
};

} // namespace game
} // namespace qwitch