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
    /// 敵対関係
    enum Relation {
        Relation_Neutral,  // 中立
        Relation_Enemy,    // 敵
        Relation_Friend,   // 味方
    };

    /// コンストラクタ
    Character();

    /// getter
    int image() const;
    Relation relation() const;

    /// setter
    void setRelation(Relation aRelation);

private:
    /// 敵対関係
    Relation mRelation;
    /// ステータス
    Status mStatus;
};

} // namespace game
} // namespace qwitch