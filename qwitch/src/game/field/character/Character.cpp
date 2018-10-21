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
    , mKind(0)
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
void Character::setKind(int aKind)
{
    mKind = aKind;
}

//---------------------------------------------------------------------
// 
//  
// 
//
int Character::image() const
{
    return Images::ins().character(mKind);
}
//---------------------------------------------------------------------
Character::Relation Character::relation() const
{
    return mRelation;
}
//---------------------------------------------------------------------
int Character::kind() const
{
    return mKind;
}

} // namespace game
} // namespace qwitch