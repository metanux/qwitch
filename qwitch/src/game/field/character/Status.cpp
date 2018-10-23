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

} // namespace game
} // namespace qwitch