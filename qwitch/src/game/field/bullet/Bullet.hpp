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
class Bullet : public FieldObject {
public:
    /// コンストラクタ
    Bullet();

    /// getter
    int image() const;

private:
};

} // namespace game
} // namespace qwitch