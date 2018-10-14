//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once

namespace qwitch {

//---------------------------------------------------------------------
// 
//  
// 
//
class AssetsManager {
public:
    static AssetsManager& ins();
    void load();
private:
    AssetsManager();
};

} // namespace qwitch