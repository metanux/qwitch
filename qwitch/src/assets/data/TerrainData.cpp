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
    : mGroupPosX()
    , mGroupPosY()
    , mGroupPosZ()
    , mGroupSizeX()
    , mGroupSizeY()
    , mGroupSizeZ()
    , mBlockX()
    , mBlockY()
    , mBlockZ()
    , mBlockKind()
    , mGroupNum()
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
void TerrainData::addGroup(
    int aPosX,
    int aPosY,
    int aPosZ,
    int aSizeX,
    int aSizeY,
    int aSizeZ)
{
    mGroupPosX.push_back(aPosX);
    mGroupPosY.push_back(aPosY);
    mGroupPosZ.push_back(aPosZ);
    mGroupSizeX.push_back(aSizeX);
    mGroupSizeY.push_back(aSizeY);
    mGroupSizeZ.push_back(aSizeZ);
    mGroupNum++;
}

//---------------------------------------------------------------------
// 
//  
// 
//
void TerrainData::addBlock(
    int a0GroupIndex,
    int aX,
    int aY,
    int aZ,
    int aKind)
{
    mBlockX.push_back(aX);
    mBlockY.push_back(aY);
    mBlockZ.push_back(aZ);
    mBlockKind.push_back(aKind);
    int group = findGroup(aX, aY, aZ);
    if (group != -1) {
        mBlockGroup.push_back(a0GroupIndex + group);
    }
    else {
        mBlockGroup.push_back(a0GroupIndex + mGroupNum);
        addGroup(aX, aY, aZ, 1, 1, 1);
    }
}

//---------------------------------------------------------------------
// 
//  
// 
//
int TerrainData::findGroup(int aX, int aY, int aZ) const
{
    int count = (int)mGroupPosX.size();
    for (int i = 0; i < count; i++) {
        if (aX < mGroupPosX[i]) { continue; }
        if (aY < mGroupPosY[i]) { continue; }
        if (aZ < mGroupPosZ[i]) { continue; }
        if (aX >= (mGroupPosX[i] + mGroupSizeX[i])) { continue; }
        if (aY >= (mGroupPosY[i] + mGroupSizeY[i])) { continue; }
        if (aZ >= (mGroupPosZ[i] + mGroupSizeZ[i])) { continue; }
        return i;
    }
    return -1;
}

//---------------------------------------------------------------------
// 
//  
// 
//
int TerrainData::countBlock() const
{
    return (int)mBlockKind.size();
}
//---------------------------------------------------------------------
int TerrainData::blockX(int aIndex) const
{
    return mBlockX[aIndex];
}
//---------------------------------------------------------------------
int TerrainData::blockY(int aIndex) const
{
    return mBlockY[aIndex];
}
//---------------------------------------------------------------------
int TerrainData::blockZ(int aIndex) const
{
    return mBlockZ[aIndex];
}
//---------------------------------------------------------------------
int TerrainData::blockKind(int aIndex) const
{
    return mBlockKind[aIndex];
}
//---------------------------------------------------------------------
int TerrainData::blockGroupId(int aIndex) const
{
    return mBlockGroup[aIndex];
}
//---------------------------------------------------------------------
int TerrainData::blockGroupPosX(int aIndex) const
{
    int id = blockGroupId(aIndex);
    return mGroupPosX[id];
}
//---------------------------------------------------------------------
int TerrainData::blockGroupPosY(int aIndex) const
{
    int id = blockGroupId(aIndex);
    return mGroupPosY[id];
}
//---------------------------------------------------------------------
int TerrainData::blockGroupPosZ(int aIndex) const
{
    int id = blockGroupId(aIndex);
    return mGroupPosZ[id];
}
//---------------------------------------------------------------------
int TerrainData::blockGroupSizeX(int aIndex) const
{
    int id = blockGroupId(aIndex);
    return mGroupSizeX[id];
}
//---------------------------------------------------------------------
int TerrainData::blockGroupSizeY(int aIndex) const
{
    int id = blockGroupId(aIndex);
    return mGroupSizeY[id];
}
//---------------------------------------------------------------------
int TerrainData::blockGroupSizeZ(int aIndex) const
{
    int id = blockGroupId(aIndex);
    return mGroupSizeZ[id];
}

} // namespace qwitch