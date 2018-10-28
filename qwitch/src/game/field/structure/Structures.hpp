//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "game/field/structure/Structure.hpp"
#include <vector>

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
class Structures {
public:
    /// コンストラクタ
    Structures();
    /// 更新処理
    void update();
    /// 読込み処理
    void load(int aAreaId);
    /// 当たり判定
    bool isCollision(const FieldObject& aObject) const;

    ///
    int countDisplayStructure() const;

    /// getter
    const Structure& structure(int aIndex);
    const Structure& displayStructure(int aIndex) const;

private:
    /// 構造物
    std::vector<Structure> mStructures;
    /// 描画オブジェクト
    std::vector<std::reference_wrapper<const Structure>> mDisplayStructures;
};

} // namespace game
} // namespace qwitch