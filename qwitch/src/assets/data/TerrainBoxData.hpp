//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include <vector>
#include "util/Vector3d.hpp"

namespace qwitch {

//---------------------------------------------------------------------
// 
//  
// 
//
class TerrainBoxData {
public:
    /// 指定エリアの反対側のindexを取得する
    static int reverseAreaIndex(int aAreaIndex);

    /// 
    static const int* surfaceXY(int aZ);
    static const int* surfaceXZ(int aY);
    static const int* surfaceYZ(int aX);

private:
    /// コンストラクタ
    TerrainBoxData();

    /// member

};

} // namespace qwitch