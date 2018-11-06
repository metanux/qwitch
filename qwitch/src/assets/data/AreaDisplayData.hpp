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
class AreaDisplayData {
public:
    /// コンストラクタ
    AreaDisplayData();
    ///
    bool isInclusion(const Vector3d& aPos) const;
    /// setter
    void add(
        int aPosX,
        int aPosY,
        int aPosZ,
        int aSizeX,
        int aSizeY,
        int aSizeZ);
    /// getter
    int count() const;

private:
    ///
    int mCount;
    /// 位置
    std::vector<Vector3d> mPos;
    /// サイズ
    std::vector<Vector3d> mSize;
};

} // namespace qwitch