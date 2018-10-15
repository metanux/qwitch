//---------------------------------------------------------------------
// 
//  
// 
//
#include "Characters.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
Characters::Characters()
    : mCharacters()
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
const Character& Characters::character(int aIndex) const
{
    return mCharacters[aIndex];
}

} // namespace game
} // namespace qwitch