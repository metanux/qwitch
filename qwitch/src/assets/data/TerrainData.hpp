//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include <vector>

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

    /// getter
    int countBlock() const;
    int x(int aIndex) const;
    int y(int aIndex) const;
    int z(int aIndex) const;
    int kind(int aIndex) const;

private:
    /// member
    std::vector<int> mX;
    std::vector<int> mY;
    std::vector<int> mZ;
    std::vector<int> mKind;
};

} // namespace qwitch