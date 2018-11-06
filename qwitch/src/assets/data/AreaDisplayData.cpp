//---------------------------------------------------------------------
// 
//  
// 
//
#include "AreaDisplayData.hpp"

namespace qwitch {

//---------------------------------------------------------------------
// 
//  
// 
//
AreaDisplayData::AreaDisplayData()
    : mCount(0)
    , mPos()
    , mSize()
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
bool AreaDisplayData::isInclusion(const Vector3d& aPos) const
{
    int n = count();
    for (int i = 0; i < n; i++) {
        if (aPos.x() < mPos[i].x()) { continue; }
        if (aPos.y() < mPos[i].y()) { continue; }
        if (aPos.z() < mPos[i].z()) { continue; }
        if (aPos.x() >= (mPos[i].x() + mSize[i].x())) { continue; }
        if (aPos.y() >= (mPos[i].y() + mSize[i].y())) { continue; }
        if (aPos.z() >= (mPos[i].z() + mSize[i].z())) { continue; }
        return true;
    }
    return false;
}

//---------------------------------------------------------------------
// 
//  
// 
//
void AreaDisplayData::add(
    int aPosX,
    int aPosY,
    int aPosZ,
    int aSizeX,
    int aSizeY,
    int aSizeZ)
{
    mPos.push_back(Vector3d(aPosX, aPosY, aPosZ));
    mSize.push_back(Vector3d(aSizeX, aSizeY, aSizeZ));
    mCount++;
}

//---------------------------------------------------------------------
// 
//  
// 
//
int AreaDisplayData::count() const
{
    return mCount;
}

} // namespace qwitch