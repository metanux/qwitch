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
class TerrainData {
public:
    TerrainData();

    /// グループの追加
    void addGroup(
        int aPosX,
        int aPosY,
        int aPosZ,
        int aSizeX,
        int aSizeY,
        int aSizeZ);

    /// ブロックの追加
    void addBlock(
        int a0GroupIndex,
        int aX,
        int aY,
        int aZ,
        int aKind);

    ///
    void set0GroupIndex(int aIndex);

    /// ブロック数のカウント
    int countBlock() const;

    /// getter
    int blockX(int aIndex) const;
    int blockY(int aIndex) const;
    int blockZ(int aIndex) const;
    int blockKind(int aIndex) const;
    int blockGroupId(int aIndex) const;
    int blockGroupPosX(int aIndex) const;
    int blockGroupPosY(int aIndex) const;
    int blockGroupPosZ(int aIndex) const;
    int blockGroupSizeX(int aIndex) const;
    int blockGroupSizeY(int aIndex) const;
    int blockGroupSizeZ(int aIndex) const;

private:
    /// どこのグループに所属しているか検索
    /// 該当なし：-1
    int findGroup(int aX, int aY, int aZ) const;

    /// member
    std::vector<int> mGroupPosX;
    std::vector<int> mGroupPosY;
    std::vector<int> mGroupPosZ;
    std::vector<int> mGroupSizeX;
    std::vector<int> mGroupSizeY;
    std::vector<int> mGroupSizeZ;
    std::vector<int> mBlockX;
    std::vector<int> mBlockY;
    std::vector<int> mBlockZ;
    std::vector<int> mBlockKind;
    std::vector<int> mBlockGroup;
    int mGroupNum;
    int m0GroupIndex;
};

} // namespace qwitch