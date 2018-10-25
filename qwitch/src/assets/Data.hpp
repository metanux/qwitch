//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include <vector>
#include "assets/data/TerrainData.hpp"
#include "assets/data/MagicData.hpp"

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
    const MagicData& magic(int aIndex) const;

private:
    /// コンストラクタ
    Data();

    /// 地形データの読込み
    void loadTerrain();
    /// 魔法データの読込み
    void loadMagic();

    /// member
    /// 地形データ
    std::vector<TerrainData> mTerrain;
    /// 魔法データ
    std::vector<MagicData> mMagic;
};

} // namespace qwitch