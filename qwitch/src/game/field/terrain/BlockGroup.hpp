//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "game/field/terrain/Block.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
class BlockGroup : public FieldObject {
public:
    /// コンストラクタ
    BlockGroup();
    /// 初期化処理
    void init();
    /// 追加処理
    void add(const Block& aBlock);

    /// getter

private:
    std::vector<std::reference_wrapper<const Block>> mBlocks;
};

} // namespace game
} // namespace qwitch