//---------------------------------------------------------------------
// 
//  
// 
//
#include "AreaData.hpp"

namespace qwitch {

//---------------------------------------------------------------------
// 
//  
// 
//
/// エリア1辺（x,y,z）のブロック数
const int AreaData::BlockNum = 16;
/// ボックスあたりのエリアの数
const int AreaData::AreaNum = 27;
/// ボックス1辺（x,y,z）のエリア数
const int AreaData::AreaNum1 = 3;
/// ボックスの中心位置のインデクス
const int AreaData::CenterIndex = 13;

//---------------------------------------------------------------------
// 
//  
// 
//
AreaData::AreaData()
    : mPos()
    , mId()
{
    mId.resize(AreaNum);
    for (int i = 0; i < AreaNum; i++) {
        mId[i] = -1;
    }
}

//---------------------------------------------------------------------
// 
//  
// 
//
int AreaData::reverseAreaIndex(int aAreaIndex)
{
    return AreaNum - aAreaIndex;
}

//---------------------------------------------------------------------
// 
//  
// 
//
int AreaData::centerAreaIndex(int aX, int aY, int aZ)
{
    int index = CenterIndex;
    if (aX > 0) { index += 1; }
    if (aX < 0) { index -= 1; }
    if (aY > 0) { index += 3; }
    if (aY < 0) { index -= 3; }
    if (aZ > 0) { index += 9; }
    if (aZ < 0) { index -= 9; }
    return index;
}

//---------------------------------------------------------------------
// 
//  
// 
//
const int* AreaData::area1(int aX, int aY, int aZ)
{
    if (aX <= -1) { return areaYZ(1); }
    if (aX >= 1) { return areaYZ(-1); }
    if (aY <= -1) { return areaXZ(1); }
    if (aY >= 1) { return areaXZ(-1); }
    if (aZ <= -1) { return areaXY(1); }
    if (aZ >= 1) { return areaXY(-1); }
    return areaXY(0);
}
//---------------------------------------------------------------------
const int* AreaData::area2(int aX, int aY, int aZ)
{
    if (aX <= -1) { return areaYZ(0); }
    if (aX >= 1) { return areaYZ(0); }
    if (aY <= -1) { return areaXZ(0); }
    if (aY >= 1) { return areaXZ(0); }
    if (aZ <= -1) { return areaXY(0); }
    if (aZ >= 1) { return areaXY(0); }
    return areaXY(0);
}
//---------------------------------------------------------------------
const int* AreaData::area3(int aX, int aY, int aZ)
{
    if (aX <= -1) { return areaYZ(-1); }
    if (aX >= 1) { return areaYZ(1); }
    if (aY <= -1) { return areaXZ(-1); }
    if (aY >= 1) { return areaXZ(1); }
    if (aZ <= -1) { return areaXY(-1); }
    if (aZ >= 1) { return areaXY(1); }
    return areaXY(0);
}
//---------------------------------------------------------------------
const int* AreaData::areaXY(int aZ)
{
    static const int surfaceXY1[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    static const int surfaceXY2[] = { 9, 10, 11, 12, 13, 14, 15, 16, 17 };
    static const int surfaceXY3[] = { 18, 19, 20, 21, 22, 23, 24, 25, 26 };
    if (aZ == -1) { return surfaceXY1; }
    if (aZ == 0) { return surfaceXY2; }
    return surfaceXY3;
}
//---------------------------------------------------------------------
const int* AreaData::areaXZ(int aY)
{
    static const int surfaceXZ1[] = { 0, 1, 2, 9, 10, 11, 18, 19, 20 };
    static const int surfaceXZ2[] = { 3, 4, 5, 12, 13, 14, 21, 22, 23 };
    static const int surfaceXZ3[] = { 6, 7, 8, 15, 16, 17, 24, 25, 26 };
    if (aY == -1) { return surfaceXZ1; }
    if (aY == 0) { return surfaceXZ2; }
    return surfaceXZ3;
}
//---------------------------------------------------------------------
const int* AreaData::areaYZ(int aX)
{
    static const int surfaceYZ1[] = { 0, 3, 6, 9, 12, 15, 18, 21, 24 };
    static const int surfaceYZ2[] = { 1, 4, 7, 10, 13, 16, 19, 22, 25 };
    static const int surfaceYZ3[] = { 2, 5, 8, 11, 14, 17, 20, 23, 26 };
    if (aX == -1) { return surfaceYZ1; }
    if (aX == 0) { return surfaceYZ2; }
    return surfaceYZ3;
}

//---------------------------------------------------------------------
// 
//  
// 
//
void AreaData::addStructure(const Vector3d& aPos, int aKind)
{
    mStructurePos.push_back(aPos);
    mStructureKind.push_back(aKind);
}

//---------------------------------------------------------------------
// 
//  
// 
//
int AreaData::countStructure() const
{
    return (int)mStructurePos.size();
}

//---------------------------------------------------------------------
// 
//  
// 
//
void AreaData::setPos(const Vector3d& aPos)
{
    mPos = aPos;
}
//---------------------------------------------------------------------
void AreaData::setId(int aAreaIndex, int aTerrainId)
{
    mId[aAreaIndex] = aTerrainId;
}

//---------------------------------------------------------------------
// 
//  
// 
//
const Vector3d& AreaData::pos() const
{
    return mPos;
}
//---------------------------------------------------------------------
int AreaData::id(int aAreaIndex) const
{
    return mId[aAreaIndex];
}
//---------------------------------------------------------------------
const Vector3d& AreaData::structurePos(int aIndex) const
{
    return mStructurePos[aIndex];
}
//---------------------------------------------------------------------
int AreaData::structureKind(int aIndex) const
{
    return mStructureKind[aIndex];
}


} // namespace qwitch