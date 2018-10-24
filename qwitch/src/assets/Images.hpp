﻿//---------------------------------------------------------------------
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
    int bullet(int aKind, int aDirection, int aIndex) const;
    int titleBack() const;

private:
    Images();
    void loadBlock();
    void loadCharacter();
    void loadBullet();

    /// member
    std::vector<int> mBlock;
    std::vector<std::vector<std::vector<int>>> mCharacter;
    std::vector<std::vector<int>> mBullet;
    int mTitleBack;
};

} // namespace qwitch