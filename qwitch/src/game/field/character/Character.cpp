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
    : mStatus()
    , mActiveMagic()
    , mPassiveMagic()
{
    /// デバッグ用
    Magic magic1;
    magic1.setId(1);
    magic1.setLevel(3);
    mActiveMagic.push_back(magic1);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Character::receiveDamage(int aDamage)
{
    mStatus.reduceHp(aDamage);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Character::reduceMp(int aValue)
{
    mStatus.reduceMp(aValue);
}

//---------------------------------------------------------------------
// 
//  
// 
//
int Character::countActiveMagic() const
{
    return (int)mActiveMagic.size();
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Character::setMagicIndex(int aIndex)
{
    mMagicIndex = aIndex;
}

//---------------------------------------------------------------------
// 
//  
// 
//
int Character::image() const
{
    int dire = direction() / 2;
    return Images::ins().character(
        kind(),
        animation().animeIndex(),
        dire,
        animation().imageIndex());
}
//---------------------------------------------------------------------
const Status& Character::status() const
{
    return mStatus;
}
//---------------------------------------------------------------------
const Magic& Character::activeMagic(int aIndex) const
{
    return mActiveMagic[aIndex];
}
//---------------------------------------------------------------------
const Magic& Character::passiveMagic(int aIndex) const
{
    return mPassiveMagic[aIndex];
}
//---------------------------------------------------------------------
int  Character::magicIndex() const
{
    return mMagicIndex;
}

} // namespace game
} // namespace qwitch