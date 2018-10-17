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
void Characters::jump(int aIndex)
{
    double jumpPower = 10;
    mCharacters[aIndex].addForce(Vector3d(0, 0, jumpPower));
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Characters::addForce(int aIndex, const Vector3d& aForce)
{
    mCharacters[aIndex].addForce(aForce);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Characters::setForceX(int aIndex, double aX)
{
    mCharacters[aIndex].setForceX(aX);
}
//---------------------------------------------------------------------
void Characters::setForceY(int aIndex, double aY)
{
    mCharacters[aIndex].setForceY(aY);
}
//---------------------------------------------------------------------
void Characters::setForceZ(int aIndex, double aZ)
{
    mCharacters[aIndex].setForceZ(aZ);
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
//---------------------------------------------------------------------
const Character& Characters::player() const
{
    return mCharacters[0];
}

} // namespace game
} // namespace qwitch