//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "game/field/FieldObject.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
class Block : public FieldObject {
public:
    /// 1ブロックのピクセルサイズ
    static const int PIXEL_SIZE;

    /// コンストラクタ
    Block();

    /// setter
    void setKind(int aKind);

    /// getter
    int image() const;

private:
    /// member
    int mKind;
};

} // namespace game
} // namespace qwitch