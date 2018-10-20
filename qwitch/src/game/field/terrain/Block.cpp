//---------------------------------------------------------------------
// 
//  
// 
//
#include "Block.hpp"
#include "assets/Images.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
const int Block::PIXEL_SIZE = 32;

//---------------------------------------------------------------------
// 
//  
// 
//
Block::Block()
    : mKind()
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Block::setKind(int aKind)
{
    mKind = aKind;
}

//---------------------------------------------------------------------
// 
//  
// 
//
int Block::image() const
{
    return Images::ins().block(mKind);
}

} // namespace game
} // namespace qwitch