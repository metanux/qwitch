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
int Character::image() const
{
    return Images::ins().character(0);
}

//---------------------------------------------------------------------
// 
//  
// 
//
Character::Relation Character::relation() const
{
    return mRelation;
}

} // namespace game
} // namespace qwitch