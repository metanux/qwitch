//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "game/field/terrain/Block.hpp"
#include "game/field/camera/Camera.hpp"
#include <vector>

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
class Terrain {
public:
    /// コンストラクタ
    Terrain();

    /// 更新処理
    void update();

    /// 表示ブロックの更新
    void updateDisplayBlocks(
        const Camera& camera);

    /// オブジェクトと地形の接触判定
    /// 
    bool isCollision(const FieldObject& aObject) const;

    /// 描画ブロック取得
    const Block& block(int aIndex) const;

    /// 描画ブロックの数取得
    int blockNum() const;

private:
    /// 1エリアの1辺（x,y,z）のブロック数
    static const int AREA_BLOCK_NUM = 48;

    /// 地形データの読込み
    /// @param aAreaIndex 保存する場所
    /// @param aAreaNum 読み込むエリア番号
    void load(int aAreaIndex, int aAreaNum);

    /// ブロックの生成
    void createBlock(
        int aX,
        int aY,
        int aZ,
        int aBlockKind);

    /// member
    /// カメラ位置周辺のブロック
    std::vector<Block> mBlocks;

    /// 描画ブロック
    std::vector<std::reference_wrapper<const Block>> mDisplayBlocks;

    /// 当たり判定
    //std::vector<int> mCollision;
    int mCollision[AREA_BLOCK_NUM][AREA_BLOCK_NUM][AREA_BLOCK_NUM];

    /// エリア0の左上マップ座標
    Vector3d mArea0MapPos;
};

} // namespace game
} // namespace qwitch