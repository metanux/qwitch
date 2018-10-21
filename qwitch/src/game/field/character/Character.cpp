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
int Character::image() const
{
    /*
    int d =
        (direction() == FieldObject::Direction_Down) ? 0 :
        (direction() == FieldObject::Direction_LeftDown) ? 0 :
        (direction() == FieldObject::Direction_Left) ? 1 :
        (direction() == FieldObject::Direction_LeftUp) ? 1 :
        (direction() == FieldObject::Direction_Up) ? 2 :
        (direction() == FieldObject::Direction_Right_Up) ? 2 :
        (direction() == FieldObject::Direction_Right) ? 3 :
        (direction() == FieldObject::Direction_Right_Down) ? 3 : 0;
    */
    int d = direction() / 2;
    return Images::ins().character(kind(), animeKind(), d, animeIndex());
}
//---------------------------------------------------------------------
Character::Relation Character::relation() const
{
    return mRelation;
}

} // namespace game
} // namespace qwitch