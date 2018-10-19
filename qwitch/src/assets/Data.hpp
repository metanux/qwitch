//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include <vector>
#include "assets/data/TerrainData.hpp"

namespace qwitch {

//---------------------------------------------------------------------
// 
//  
// 
//
class Data {
public:
    static Data& ins();
    void load();

    /// getter
    const TerrainData& terrain(int aIndex) const;

private:
    /// コンストラクタ
    Data();

    /// 地形データの読込み
    void loadTerrain();

    /// 地形データのリンク情報
    void loadTerrainLink();

    ///
    int reverseAreaIndex(int aAreaIndex) const;

    /// member
    std::vector<TerrainData> mTerrain;
};

} // namespace qwitch