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
    /// シングルトン
    static Data& ins();

    /// ロード
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