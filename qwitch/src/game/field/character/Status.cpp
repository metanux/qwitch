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
    , mMoveSpeed(3.0)
    , mJumpPower(10)
{
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