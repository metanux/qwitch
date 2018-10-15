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
    Block block;
    mBlocks.push_back(block);
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