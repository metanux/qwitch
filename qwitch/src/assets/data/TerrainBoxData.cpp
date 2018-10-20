//---------------------------------------------------------------------
// 
//  
// 
//
#include "TerrainBoxData.hpp"

namespace qwitch {

//---------------------------------------------------------------------
// 
//  
// 
//
TerrainBoxData::TerrainBoxData()
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
int TerrainBoxData::reverseAreaIndex(int aAreaIndex)
{
    return 26 - aAreaIndex;
}

//---------------------------------------------------------------------
// 
//  
// 
//
const int* TerrainBoxData::surfaceXY(int aZ)
{
    static const int surfaceXY1[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    static const int surfaceXY2[] = { 9, 10, 11, 12, 13, 14, 15, 16, 17 };
    static const int surfaceXY3[] = { 18, 19, 20, 21, 22, 23, 24, 25, 26 };
    if (aZ == -1) { return surfaceXY1; }
    if (aZ == 0) { return surfaceXY2; }
    return surfaceXY3;
}
//---------------------------------------------------------------------
const int* TerrainBoxData::surfaceXZ(int aY)
{
    static const int surfaceXZ1[] = { 0, 1, 2, 9, 10, 11, 18, 19, 20 };
    static const int surfaceXZ2[] = { 3, 4, 5, 12, 13, 14, 21, 22, 23 };
    static const int surfaceXZ3[] = { 6, 7, 8, 15, 16, 17, 24, 25, 26 };
    if (aY == -1) { return surfaceXZ1; }
    if (aY == 0) { return surfaceXZ2; }
    return surfaceXZ3;
}
//---------------------------------------------------------------------
const int* TerrainBoxData::surfaceYZ(int aX)
{
    static const int surfaceYZ1[] = { 0, 3, 6, 9, 12, 15, 18, 21, 24 };
    static const int surfaceYZ2[] = { 1, 4, 7, 10, 13, 16, 19, 22, 25 };
    static const int surfaceYZ3[] = { 2, 5, 8, 11, 14, 17, 20, 23, 26 };
    if (aX == -1) { return surfaceYZ1; }
    if (aX == 0) { return surfaceYZ2; }
    return surfaceYZ3;
}

} // namespace qwitch