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
class AreaData {
public:
    /// エリア1辺（x,y,z）のブロック数
    static const int BlockNum;
    /// ボックスあたりのエリアの数
    static const int AreaNum;
    /// ボックス1辺（x,y,z）のエリア数
    static const int AreaNum1;
    /// ボックスの中心位置のインデクス
    static const int CenterIndex;

    /// 指定エリアの反対側のindexを取得する
    static int reverseAreaIndex(int aAreaIndex);
    ///
    static int centerAreaIndex(int aX, int aY, int aZ);
    /// エリアindex
    static const int* area1(int aX, int aY, int aZ);
    static const int* area2(int aX, int aY, int aZ);
    static const int* area3(int aX, int aY, int aZ);
    static const int* areaXY(int aZ);
    static const int* areaXZ(int aY);
    static const int* areaYZ(int aX);

    /// コンストラクタ
    AreaData();

    /// 構造物追加
    void addStructure(const Vector3d& aPos, int aKind);
    /// 構造物の数
    int countStructure() const;

    /// 
    void setPos(const Vector3d& aPos);
    void setId(int aAreaIndex, int aTerrainId);

    /// getter
    const Vector3d& pos() const;
    int id(int aAreaIndex) const;
    const Vector3d& structurePos(int aIndex) const;
    int structureKind(int aIndex) const;

private:
    /// member
    /// (0, 0, 0)の座標
    Vector3d mPos;
    /// 近傍のエリアID
    std::vector<int> mId;
    /// 構造物
    std::vector<Vector3d> mStructurePos;
    std::vector<int> mStructureKind;
};

} // namespace qwitch