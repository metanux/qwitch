//---------------------------------------------------------------------
// 
//  
// 
//
#include "BlockGroup.hpp"
#include "assets/Images.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
BlockGroup::BlockGroup()
    : mBlocks()
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
void BlockGroup::init()
{
    mBlocks.clear();
}

//---------------------------------------------------------------------
// 
//  
// 
//
void BlockGroup::add(const Block& aBlock)
{
    //----- 画像の追加
    int handl = aBlock.images()[0].handl();
    addImage(handl, aBlock.pos(), aBlock.size());

    //-----
    mBlocks.push_back(aBlock);
}

} // namespace game
} // namespace qwitch