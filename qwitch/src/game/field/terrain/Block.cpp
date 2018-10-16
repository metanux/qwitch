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
const int Block::PIXEL_SIZE = 16;

//---------------------------------------------------------------------
// 
//  
// 
//
Block::Block()
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
int Block::image() const
{
    return Images::ins().block(0);
}

} // namespace game
} // namespace qwitch