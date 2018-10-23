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
class FieldParameter {
public:
    /// 描画範囲
    static const int RenderAreaSize;
    /// プレイヤーindex
    static const int PlayerIndex;

private:
    /// コンストラクタ
    FieldParameter();
};

} // namespace game
} // namespace qwitch