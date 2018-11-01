﻿//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "game/field/terrain/Block.hpp"
#include "game/field/camera/Camera.hpp"
#include "game/field/terrain/BlockGroup.hpp"
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
    void update(const Camera& camera);
    /// 読込み処理
    void load(int aAreaId);
    /// スクロール
    void scroll(int aX, int aY, int aZ);
    /// 当たり判定
    bool isCollision(const FieldObject& aObject) const;

    /// getter
    /// 描画ブロック数
    int countBlock() const;
    /// グループ数
    int countGroup() const;

    /// 描画ブロック
    const Block& block(int aIndex) const;
    /// グループ
    const BlockGroup& group(int aIndex) const;

private:
    /// 表示ブロックの更新処理
    void updateDisplayBlocks(const Camera& camera);
    /// 読込み処理
    void load(int aAreaIndex, int aAreaId);
    /// ブロックの生成
    void createBlock(
        int aAreaIndex,
        int aX,
        int aY,
        int aZ,
        int aBlockKind,
        int aGroupId,
        int aGroupPosX,
        int aGroupPosY,
        int aGroupPosZ,
        int aGroupSizeX,
        int aGroupSizeY,
        int aGroupSizeZ);
    /// ソート
    void sort();
    /// 挿入ソート
    void insertSortedBlocks(const Block& aBlock);
    /// 順序関係の決定
    void determOrder();
    /// ブロックの削除
    void deleteArea(int aAreaIndex);
    /// 当たり判定の設定
    void setCollision(int aAreaIndex, int aX, int aY, int aZ);
    /// getter
    int collision(int aX, int aY, int aZ) const;
    int convertAreaIndex(int aX, int aY, int aZ) const;

    /// ブロック
    std::vector<std::vector<Block>> mBlocks;
    /// ソート済みブロック
    std::vector<std::reference_wrapper<const Block>> mSortedBlocks;
    /// 描画ブロック
    std::vector<std::reference_wrapper<const Block>> mDisplayBlocks;
    /// ブロックグループ
    std::vector<BlockGroup> mGroups;
    /// 当たり判定
    std::vector<std::vector<std::vector<std::vector<int>>>> mCollision;
};

} // namespace game
} // namespace qwitch