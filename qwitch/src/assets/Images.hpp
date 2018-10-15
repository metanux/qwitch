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
    int character(int aIndex) const;
    int titleBack() const;

private:
    Images();

    /// member
    std::vector<int> mBlock;
    std::vector<int> mCharacter;
    int mTitleBack;
};

} // namespace qwitch