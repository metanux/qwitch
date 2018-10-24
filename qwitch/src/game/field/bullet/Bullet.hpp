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

    /// 更新処理
    void update();

    ///
    bool isDelete() const;

    /// getter
    int image() const;

private:
    /// 経過フレーム
    int mFrame;
};

} // namespace game
} // namespace qwitch