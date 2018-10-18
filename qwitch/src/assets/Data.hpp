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

    /// member
    std::vector<TerrainData> mTerrain;
};

} // namespace qwitch