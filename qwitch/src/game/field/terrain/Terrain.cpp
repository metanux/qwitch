//---------------------------------------------------------------------
// 
//  
// 
//
#include "Terrain.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
Terrain::Terrain()
    : mBlocks()
{
    /// デバッグ用
    for (int y = 0; y < 2; y++) {
        for (int x = 0; x < 2; x++) {
            Block block;
            block.setPos(Vector3d(32 * x, 32 * y, 0));
            block.setSize(Vector3d(32, 32, 32));
            mBlocks.push_back(block);
        }
    }
}

//---------------------------------------------------------------------
// 
//  
// 
//
int Terrain::countBlocks() const
{
    return (int)mBlocks.size();
}

//---------------------------------------------------------------------
// 
//  
// 
//
const Block& Terrain::block(int aIndex) const
{
    return mBlocks[aIndex];
}

} // namespace game
} // namespace qwitch