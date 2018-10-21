//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include <vector>

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
class Status {
public:
    Status();

    int hp() const;

private:
    /// 現在のHP
    int mHp;
};

} // namespace game
} // namespace qwitch