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
    : mRelation(Relation_Neutral)
    , mStatus()
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Character::setRelation(Relation aRelation)
{
    mRelation = aRelation;
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
Character::Relation Character::relation() const
{
    return mRelation;
}
//---------------------------------------------------------------------
const Status& Character::status() const
{
    return mStatus;
}

} // namespace game
} // namespace qwitch