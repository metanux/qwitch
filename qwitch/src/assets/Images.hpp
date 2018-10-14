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
class Images {
public:
    static Images& ins();
    void load();

    /// getter
    int block(int aIndex) const;
    int chara(int aKind, int aIndex) const;
    int monster(int aKind, int aIndex) const;
    int titleBack() const;

private:
    Images();

    /// member
    int mBlock[10];
    std::vector<std::vector<int>> mChara;
    std::vector<std::vector<int>> mMonster;
    int mTitleBack;
};

} // namespace qwitch