//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "util/Vector3d.hpp"

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
    void update();

    void setScrollPos(const Vector3d& aPos);

    /// getter
    const Vector3d& pos() const;

private:
    /// カメラの現在座標
    Vector3d mPos;

    /// カメラをスクロールさせる座標
    Vector3d mScrollPos;
};

} // namespace game
} // namespace qwitch