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
    Character character;
    character.setPos(Vector3d(0, 0, 32));
    character.setSize(Vector3d(32, 32, 64));
    mCharacters.push_back(character);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Characters::move(int aIndex, const Vector3d& aPos)
{
    mCharacters[aIndex].move(aPos);
}

//---------------------------------------------------------------------
// 
//  
// 
//
int Characters::countCharacter() const
{
    return (int)mCharacters.size();
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