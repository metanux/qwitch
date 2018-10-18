//---------------------------------------------------------------------
// 
//  
// 
//
#include "TerrainData.hpp"
#include "game/field/terrain/Terrain.hpp"

namespace qwitch {

//---------------------------------------------------------------------
// 
//  
// 
//
TerrainData::TerrainData()
    : mX()
    , mY()
    , mZ()
    , mKind()
    , mPos()
    , mId()
{
    mId.resize(game::Terrain::AREA_NUM);
    for (int i = 0; i < game::Terrain::AREA_NUM; i++) {
        mId[i] = -1;
    }
}

//---------------------------------------------------------------------
// 
//  
// 
//
void TerrainData::addBlock(
    int aX,
    int aY,
    int aZ,
    int aKind)
{
    mX.push_back(aX);
    mY.push_back(aY);
    mZ.push_back(aZ);
    mKind.push_back(aKind);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void TerrainData::setPos(const Vector3d& aPos)
{
    mPos = aPos;
}
//---------------------------------------------------------------------
void TerrainData::setId(int aAreaIndex, int aTerrainId)
{
    mId[aAreaIndex] = aTerrainId;
}

//---------------------------------------------------------------------
// 
//  
// 
//
int TerrainData::countBlock() const
{
    return (int)mX.size();
}
//---------------------------------------------------------------------
int TerrainData::x(int aIndex) const
{
    return mX[aIndex];
}
//---------------------------------------------------------------------
int TerrainData::y(int aIndex) const
{
    return mY[aIndex];
}
//---------------------------------------------------------------------
int TerrainData::z(int aIndex) const
{
    return mZ[aIndex];
}
//---------------------------------------------------------------------
int TerrainData::kind(int aIndex) const
{
    return mKind[aIndex];
}
//---------------------------------------------------------------------
const Vector3d& TerrainData::pos() const
{
    return mPos;
}
//---------------------------------------------------------------------
int TerrainData::id(int aAreaIndex) const
{
    return mId[aAreaIndex];
}

} // namespace qwitch