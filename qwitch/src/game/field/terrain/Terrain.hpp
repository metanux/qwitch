//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "game/field/terrain/Block.hpp"
#include <vector>

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
class Terrain {
public:
    Terrain();

    /// ブロック数のカウント
    int countBlocks() const;

    /// getter
    const Block& block(int aIndex) const;

private:
    /// member
    std::vector<Block> mBlocks;
};

} // namespace game
} // namespace qwitch