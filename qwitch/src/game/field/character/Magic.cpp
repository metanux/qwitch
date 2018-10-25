//---------------------------------------------------------------------
// 
//  
// 
//
#include "Magic.hpp"
#include "assets/Data.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
Magic::Magic()
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Magic::setId(int aId)
{
    mId = aId;
}
//---------------------------------------------------------------------
void Magic::setLevel(int aLevel)
{
    mLevel = aLevel;
}


//---------------------------------------------------------------------
// 
//  
// 
//
int Magic::id() const
{
    return mId;
}
//---------------------------------------------------------------------
int Magic::level() const
{
    return mLevel;
}
//---------------------------------------------------------------------
int Magic::rank() const
{
    return Data::ins().magic(mId).rank();
}
//---------------------------------------------------------------------
int Magic::attack() const
{
    return Data::ins().magic(mId).value("攻撃力", mLevel);
}
//---------------------------------------------------------------------
int Magic::mp() const
{
    return Data::ins().magic(mId).value("消費MP", mLevel);
}

} // namespace game
} // namespace qwitch