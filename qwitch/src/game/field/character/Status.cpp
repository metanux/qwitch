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
    , mHpMax(100)
    , mMp(100)
    , mMpMax(100)
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
    if (mHp < 0) {
        mHp = 0;
    }
}
//---------------------------------------------------------------------
void Status::reduceMp(int aValue)
{
    mMp -= aValue;
    if (mMp < 0) {
        mMp = 0;
    }
}

//---------------------------------------------------------------------
// 
//  
// 
//
bool Status::isDeath() const
{
    return (mHp <= 0);
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
int Status::hpMax() const
{
    return mHpMax;
}
//---------------------------------------------------------------------
double Status::hpRate() const
{
    return (double)mHp / mHpMax;
}
//---------------------------------------------------------------------
int Status::mp() const
{
    return mMp;
}
//---------------------------------------------------------------------
int Status::mpMax() const
{
    return mMpMax;
}
//---------------------------------------------------------------------
double Status::mpRate() const
{
    return (double)mMp / mMpMax;
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