﻿//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "game/field/object/FieldObject.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
class Structure : public FieldObject {
public:
    /// コンストラクタ
    Structure();

    /// 更新処理
    void update();

    /// getter
private:
};

} // namespace game
} // namespace qwitch