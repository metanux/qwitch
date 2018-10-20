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
    /// エリア1辺（x,y,z）のブロック数
    static const int AREA_BLOCK_NUM = 16;

    /// ボックスあたりのエリアの数
    static const int AREA_NUM = 27;

    /// ボックス1辺（x,y,z）のエリア数
    static const int AREA_NUM_1 = 3;

    /// ボックスの中心位置のインデクス
    static const int CENTER_AREA_INDEX = 13;

    /// コンストラクタ
    Terrain();

    /// 更新処理
    void update(
        const Camera& camera);

    /// 地形データの読込み
    /// 3*3*3のエリア情報を読み込む
    void load(
        int aCenterTerrainIndex);

    /// オブジェクトと地形の接触判定
    /// @param aObject 判定するオブジェクト
    bool isCollision(
        const FieldObject& aObject) const;

    /// 描画ブロック取得
    const Block& block(
        int aIndex) const;

    /// 描画ブロックの数取得
    int blockNum() const;

private:
    /// 表示ブロックの更新
    void updateDisplayBlocks(const Camera& camera);

    /// 地形データの読込み
    /// @param aAreaIndex 保存する場所
    /// @param aTerrainIndex 読み込む地形データの番号
    void loadArea(
        int aAreaIndex,
        int aTerrainId);

    /// エリア移動
    void scroll(
        int dx,
        int dy,
        int dz);

    /// ブロックを描画順にソート
    /// 結果をmSortedBlocksに格納
    void sortBlocks();

    /// 整列済みブロックに新しいブロックを挿入する
    void insertSortedBlocks(
        const Block& aBlock);

    /// ブロックの生成
    void createBlock(
        int aAreaIndex,
        int aX,
        int aY,
        int aZ,
        int aBlockKind,
        const Vector3d& aAreaPos);

    /// 配列にブロックを追加する
    void addBlock(
        int aAreaIndex,
        const Block& block);

    /// ブロックの削除
    void deleteArea(int aAreaIndex);

    /// 当たり判定
    int collision(int aX, int aY, int aZ) const;

    /// 当たり判定の設定
    void setCollision(int aAreaIndex, int aX, int aY, int aZ);

    /// areaIndexへの変換
    int convertAreaIndex(int aX, int aY, int aZ) const;

    /// member
    /// カメラ位置周辺のブロック
    std::vector <std::vector<Block>> mBlocks;

    /// 整列済みブロック
    std::vector<std::reference_wrapper<const Block>> mSortedBlocks;

    /// 描画ブロック
    std::vector<std::reference_wrapper<const Block>> mDisplayBlocks;

    /// 当たり判定
    //std::vector<int> mCollision;
    int mCollision[AREA_NUM][AREA_BLOCK_NUM][AREA_BLOCK_NUM][AREA_BLOCK_NUM];

    /// エリア0(x:0,y:0,z:0)の座標
    Vector3d mArea0Pos;

    /// 
    std::vector<int> mAreaIndex;

    /// 中心位置のterrainId
    int mCenterTerrainId;
};

} // namespace game
} // namespace qwitch