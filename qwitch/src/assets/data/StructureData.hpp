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
class StructureData {
public:
    /// コンストラクタ
    StructureData(
        int aSizeX,
        int aSizeY,
        int aSizeZ);

    /// size
    const Vector3d& size() const;
    int sizeX() const;
    int sizeY() const;
    int sizeZ() const;

private:
    Vector3d mSize;
};

} // namespace qwitch