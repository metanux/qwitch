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