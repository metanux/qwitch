//---------------------------------------------------------------------
// 
//  
// 
//
#include "Character.hpp"
#include "assets/Images.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
Character::Character()
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
int Character::image() const
{
    return Images::ins().character(0);
}

} // namespace game
} // namespace qwitch