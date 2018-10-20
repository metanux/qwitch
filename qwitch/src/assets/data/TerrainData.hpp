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

    /// ブロックの追加
    void addBlock(
        int aX,
        int aY,
        int aZ,
        int aKind);

    /// 
    void setPos(const Vector3d& aPos);
    void setId(int aAreaIndex, int aTerrainId);

    /// ブロック数のカウント
    int countBlock() const;

    /// getter
    int x(int aIndex) const;
    int y(int aIndex) const;
    int z(int aIndex) const;
    int kind(int aIndex) const;
    const Vector3d& pos() const;
    int id(int aAreaIndex) const;

private:
    /// member
    std::vector<int> mX;
    std::vector<int> mY;
    std::vector<int> mZ;
    std::vector<int> mKind;
    /// (0, 0, 0)の座標
    Vector3d mPos;
    /// 近傍のエリアID
    std::vector<int> mId;
};

} // namespace qwitch