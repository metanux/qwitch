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
    int titleBack() const;

private:
    Images();

    /// member
    std::vector<int> mBlock;
    int mTitleBack;
};

} // namespace qwitch