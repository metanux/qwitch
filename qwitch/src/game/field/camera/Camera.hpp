//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "util/Vector3d.hpp"
#include "game/field/FieldObject.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
class Camera {
public:
    Camera();

    /// 状態更新処理
    void update();
    
    /// 状態更新処理
    /// 引数のオブジェクトを追跡する
    void update(const FieldObject& aObject);

    /// getter
    const Vector3d& windowPos() const;
    const Vector3d& fieldPos() const;

private:
    /// 現在位置の更新
    void updatePos();

    /// フィールド上の座標
    Vector3d mFieldPos;

    /// カメラをスクロールさせる座標
    Vector3d mScrollPos;

    /// カメラの現在ピクセル座標
    Vector3d mWindowPos;

};

} // namespace game
} // namespace qwitch