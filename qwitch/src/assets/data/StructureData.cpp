//---------------------------------------------------------------------
// 
//  
// 
//
#include "StructureData.hpp"

namespace qwitch {

//---------------------------------------------------------------------
// 
//  
// 
//
StructureData::StructureData(
    int aSizeX,
    int aSizeY,
    int aSizeZ)
    : mSize(aSizeX, aSizeY, aSizeZ)
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
const Vector3d& StructureData::size() const
{
    return mSize;
}
//---------------------------------------------------------------------
int StructureData::sizeX() const
{
    return (int)mSize.x();
}
//---------------------------------------------------------------------
int StructureData::sizeY() const
{
    return (int)mSize.y();
}
//---------------------------------------------------------------------
int StructureData::sizeZ() const
{
    return (int)mSize.z();
}

} // namespace qwitch