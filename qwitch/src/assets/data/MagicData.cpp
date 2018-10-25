//---------------------------------------------------------------------
// 
//  
// 
//
#include "MagicData.hpp"

namespace qwitch {

//---------------------------------------------------------------------
// 
//  
// 
//
MagicData::MagicData()
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
void MagicData::setId(int aId)
{
    mId = aId;
}
//---------------------------------------------------------------------
void MagicData::setName(std::string aName)
{
    mName = aName;
}
//---------------------------------------------------------------------
void MagicData::setRank(int aId)
{
    mId = aId;
}
//---------------------------------------------------------------------
void MagicData::addValue(std::string aKind, int aBase, int aLevel)
{
    int index = (int)mValueBase.size();
    mValueIndex[aKind] = index;
    mValueBase.push_back(aBase);
    mValueLevel.push_back(aLevel);
}

//---------------------------------------------------------------------
// 
//  
// 
//
int MagicData::id() const
{
    return mId;
}
//---------------------------------------------------------------------
std::string MagicData::name() const
{
    return mName;
}
//---------------------------------------------------------------------
int MagicData::rank() const
{
    return mRank;
}
//---------------------------------------------------------------------
int MagicData::value(std::string aKind, int aLevel) const
{
    int index = mValueIndex.at(aKind);
    return (mValueBase[index] + mValueLevel[index] * (aLevel - 1));
}

} // namespace qwitch