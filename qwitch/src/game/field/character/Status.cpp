//---------------------------------------------------------------------
// 
//  
// 
//
#include "Status.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
Status::Status()
    : mHp(100)
    , mAttack(10)
    , mMoveSpeed(3.0)
    , mJumpPower(10)
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Status::reduceHp(int aValue)
{
    mHp -= aValue;
}

//---------------------------------------------------------------------
// 
//  
// 
//
int Status::hp() const
{
    return mHp;
}
//---------------------------------------------------------------------
int Status::attack() const
{
    return mAttack;
}
//---------------------------------------------------------------------
double Status::moveSpeed() const
{
    return mMoveSpeed;
}
//---------------------------------------------------------------------
double Status::jumpPower() const
{
    return mJumpPower;
}

} // namespace game
} // namespace qwitch