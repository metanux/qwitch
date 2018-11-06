//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include <vector>
#include "assets/data/AreaData.hpp"
#include "assets/data/AreaDisplayData.hpp"
#include "assets/data/TerrainData.hpp"
#include "assets/data/MagicData.hpp"
#include "assets/data/StructureData.hpp"

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

    /// 表示エリア関係
    int findAreaDisplayId(const Vector3d& aPos) const;
    bool isDisplay(int aId, const Vector3d& aPos) const;

    /// getter
    const AreaData& area(int aId) const;
    const AreaDisplayData& areaDisplay(int aId) const;
    const TerrainData& terrain(int aId) const;
    const MagicData& magic(int aId) const;
    const StructureData& structure(int aId) const;

private:
    /// コンストラクタ
    Data();

    /// フィールドエリアデータ読込み
    void loadArea();
    ///
    void loadAreaDisplay();
    /// 地形データの読込み
    void loadTerrain();
    /// 魔法データの読込み
    void loadMagic();
    /// 構造物データの読込み
    void loadStructure();

    /// member
    /// フィールドエリアデータ
    std::vector<AreaData> mArea;
    ///
    std::vector<AreaDisplayData> mAreaDisplay;
    /// 地形データ
    std::vector<TerrainData> mTerrain;
    /// 魔法データ
    std::vector<MagicData> mMagic;
    /// 構造物データ
    std::vector<StructureData> mStructure;
};

} // namespace qwitch