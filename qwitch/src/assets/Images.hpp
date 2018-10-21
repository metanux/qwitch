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
    int character(int aKind, int aAnime, int aDirection, int aIndex) const;
    int titleBack() const;

private:
    Images();
    void loadBlock();
    void loadCharacter();

    /// member
    std::vector<int> mBlock;
    std::vector<std::vector<std::vector<int>>> mCharacter;
    int mTitleBack;
};

} // namespace qwitch